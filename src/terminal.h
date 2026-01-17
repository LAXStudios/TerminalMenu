//
// Created by lax on 1/15/26.
//

#ifndef TERMINALMENU_TERMINAL_H
#define TERMINALMENU_TERMINAL_H

#include <termios.h>
#include <unistd.h>

enum class Key {
    ArrowUp,
    ArrowDown,
    ArrowRight,
    ArrowLeft,
    Char,
    Unknown
};

class RawMode {
    public:
    RawMode() {
        tcgetattr(STDIN_FILENO, &orig_);
        raw_ = orig_;
        raw_.c_lflag &= ~(ECHO|ICANON|ISIG);
        raw_.c_cc[VMIN] = 0;
        raw_.c_cc[VTIME] = 1;
        tcsetattr(STDIN_FILENO, TCSANOW, &raw_);
    }
    ~RawMode() {
        tcsetattr(STDIN_FILENO, TCIOFLUSH, &orig_);
    }

    // Das Objekt soll single bleiben, wie ich :D
    RawMode(const RawMode&) = delete;
    RawMode& operator=(const RawMode&) = delete;

private:
    struct termios orig_{}, raw_{};
};

struct KeyResult {
    Key keyType;
    char character;
};

inline char readByte() {
    char c{};
    while (read(STDIN_FILENO, &c, 1) != 1) {}
    return c;
}

inline KeyResult readKey() {
    if (const char firstCase = readByte(); firstCase != '\x1b')
        return {Key::Unknown, firstCase};

    if (const char secondCase = readByte(); secondCase != '[')
        return {Key::Unknown, 0};

    switch (char thirdCase = readByte()) {
        case 'A': return {Key::ArrowUp, 0};
        case 'B': return {Key::ArrowDown, 0};
        case 'C': return {Key::ArrowRight, 0};
        case 'D': return {Key::ArrowLeft, 0};
        default: return {Key::Unknown, 0};
    }
}

inline void clearScreen() {
    std::cout << "\033[2J\033[1;1H" << std::flush;
}

#endif //TERMINALMENU_TERMINAL_H