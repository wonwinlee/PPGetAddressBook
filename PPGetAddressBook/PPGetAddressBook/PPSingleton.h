
//
//  PPSingleton.h
//  PPGetAddressBook
//
//  Created by AndyPang on 16/9/19.
//  Copyright © 2016年 AndyPang. All rights reserved.
//

/*
 *********************************************************************************
 *
 * 如果您在使用 PPGetAddressBook 的过程中出现bug或有更好的建议,还请及时以下列方式联系我,我会及
 * 时修复bug,解决问题.
 *
 * Weibo : CoderPang
 * Email : jkpang@outlook.com
 * QQ    : 2406552315
 * GitHub: https://github.com/jkpang
 *
 * PS:我的另外两个很好用的封装,欢迎使用!
 * 1.对AFNetworking 3.x 与YYCache的二次封装,一句代码搞定数据请求与缓存,告别FMDB:
 *   GitHub:https://github.com/jkpang/PPNetworkHelper
 * 2.仿京东淘宝商品数量的加减按钮,可定制程度高,使用简单:
 *   GitHub:https://github.com/jkpang/PPNumberButton
 *
 *********************************************************************************
 */

#ifndef PPSingleton_h
#define PPSingleton_h

// .h文件
#define PPSingletonH(name) + (instancetype)shared##name;

// .m文件
#define PPSingletonM(name) \
static id _instance; \
 \
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [super allocWithZone:zone]; \
    }); \
    return _instance; \
} \
 \
+ (instancetype)shared##name \
{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [[self alloc] init]; \
    }); \
    return _instance; \
} \
 \
- (id)copyWithZone:(NSZone *)zone \
{ \
    return _instance; \
}

#endif /* PPSingleton_h */
