#include <memory.h>

#include <csetjmp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


using namespace std;

// 果然没那么简单。。爆内存了
class TextEditor_0 {
public:
    TextEditor_0() : text_(""), cursor_(0) {}

    void addText(string text) {
        // string head = text_.substr(0, cursor_);
        // string tail = text_.substr(cursor_);
        // text_ = head + text + tail;
        text_ = text_.substr(0, cursor_) + text + text_.substr(cursor_);
        cursor_ += text.size();
    }

    int deleteText(int k) {
        if (k >= cursor_) {
            int old_cursor = cursor_;
            text_ = text_.substr(cursor_);
            cursor_ = 0;
            return old_cursor;
        } else {
            // string head = text_.substr(0, (cursor_ - k));
            // string tail = text_.substr(cursor_);
            // text_ = head + tail;
            text_ = text_.substr(0, (cursor_ - k)) + text_.substr(cursor_);
            cursor_ -= k;
            return k;
        }
    }

    string cursorLeft(int k) {
        cursor_ = cursor_ > k ? cursor_ - k : 0;
        int len = min(10, cursor_);
        return text_.substr(cursor_ - len, len);
    }

    string cursorRight(int k) {
        cursor_ = cursor_ + k < text_.size() ? cursor_ + k : text_.size();
        int len = min(10, cursor_);
        return text_.substr(cursor_ - len, len);
    }

    string getCurText() { return text_; }

    int getCurCursor() { return cursor_; }

private:
    string text_;
    int cursor_;
};

class TextEditor {
public:
    TextEditor() : cursor_(0) {}

    void addText(string text) {
        text_.insert(text_.begin() + cursor_, text.begin(), text.end());
        cursor_ += text.size();
    }

    int deleteText(int k) {
        int deleted = 0;
        while (cursor_ > 0 && k > 0) {
            text_.erase(text_.begin() + cursor_ - 1);
            --cursor_;
            --k;
            ++deleted;
        }
        return deleted;
    }

    string cursorLeft(int k) {
        cursor_ = cursor_ > k ? cursor_ - k : 0;
        int len = min(10, cursor_);
        return string(text_.begin() + cursor_ - len, text_.begin() + cursor_);
    }

    string cursorRight(int k) {
        cursor_ = cursor_ + k >= text_.size() ? text_.size() : cursor_ + k;
        int len = min(10, cursor_);
        return string(text_.begin() + cursor_ - len, text_.begin() + cursor_);
    }

private:
    vector<char> text_;
    int cursor_;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main() {
    TextEditor *obj = new TextEditor();
    obj->addText("leetcode");
    cout << obj->deleteText(4) << endl;
    obj->addText("practice");
    cout << obj->cursorRight(3) << endl;
    cout << obj->cursorLeft(8) << endl;
    cout << obj->deleteText(10) << endl;
    cout << obj->cursorLeft(2) << endl;
    cout << obj->cursorRight(6) << endl;
    return 0;
}