#pragma once

enum class MediaOpenFailure {
    None,
    InvalidConfiguration,
    AcbCreate,
    AcbInitialize,
    MediaIdRegistration,
    StarfishLoad
};

inline const char *media_open_failure_message(MediaOpenFailure failure) {
    switch (failure) {
    case MediaOpenFailure::InvalidConfiguration: return "无法启动视频播放（媒体配置无效）。";
#if defined(UXAIR_MEDIA_NDL)
    case MediaOpenFailure::AcbCreate: return "无法启动视频播放（视频窗口创建失败）。";
#else
    case MediaOpenFailure::AcbCreate: return "无法启动视频播放（ACB 创建失败）。";
#endif
    case MediaOpenFailure::AcbInitialize: return "无法启动视频播放（ACB 初始化失败）。";
    case MediaOpenFailure::MediaIdRegistration: return "无法启动视频播放（ACB 媒体注册失败）。";
#if defined(UXAIR_MEDIA_NDL)
    case MediaOpenFailure::StarfishLoad: return "无法启动视频播放（NDL 加载失败）。";
#else
    case MediaOpenFailure::StarfishLoad: return "无法启动视频播放（Starfish 加载失败）。";
#endif
    case MediaOpenFailure::None: break;
    }
    return "无法启动视频播放。";
}
