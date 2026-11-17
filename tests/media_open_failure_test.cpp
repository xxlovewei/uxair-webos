#include "media_open_failure.h"
#include <cassert>
#include <cstring>

int main() {
    assert(std::strcmp(media_open_failure_message(MediaOpenFailure::None),
                       "无法启动视频播放。")==0);
    assert(std::strcmp(media_open_failure_message(MediaOpenFailure::StarfishLoad),
                       "无法启动视频播放（Starfish 加载失败）。") == 0);
    assert(std::strcmp(media_open_failure_message(MediaOpenFailure::AcbInitialize),
                       "无法启动视频播放（ACB 初始化失败）。") == 0);
}
