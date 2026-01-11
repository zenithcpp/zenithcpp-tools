#pragma once
#include <zenith/constexpr_string_view.hpp>
#include <array>

namespace zenith::parser {

enum class token_type : std::uint8_t {
    identifier,
    number,
    keyword,
    punctuation,
    whitespace,
    eof
};

struct token {
    constexpr_string_view text;
    token_type type = token_type::eof;
    constexpr token() = default;
    constexpr token(constexpr_string_view t, token_type ty) : text(t), type(ty) {}
};

template<std::size_t N>
consteval auto lex(const char (&source)[N]) {
    using cs = const_string<N>;
    constexpr cs src = source;

    std::array<token, 512> tokens{};
    std::size_t count = 0;
    std::size_t pos = 0;

    while (pos < src.size()) {
        if (src[pos] == ' ' || src[pos] == '\t' || src[pos] == '\n' || src[pos] == '\r') {
            ++pos;
            continue;
        }

        if ((src[pos] >= 'a' && src[pos] <= 'z') || (src[pos] >= 'A' && src[pos] <= 'Z') || src[pos] == '_') {
            std::size_t start = pos;
            while (pos < src.size() && ((src[pos] >= 'a' && src[pos] <= 'z') ||
                                        (src[pos] >= 'A' && src[pos] <= 'Z') ||
                                        (src[pos] >= '0' && src[pos] <= '9') || src[pos] == '_'))
                ++pos;
            tokens[count++] = {src.view().substr(start, pos-start), token_type::identifier};
        }
        else if (src[pos] >= '0' && src[pos] <= '9') {
            std::size_t start = pos;
            while (pos < src.size() && src[pos] >= '0' && src[pos] <= '9') ++pos;
            tokens[count++] = {src.view().substr(start, pos-start), token_type::number};
        }
        else {
            tokens[count++] = {{&src[pos], 1}, token_type::punctuation};
            ++pos;
        }
    }

    tokens[count++] = {{}, token_type::eof};
    return std::pair{tokens, count};
}

} // namespace zenith::parser
