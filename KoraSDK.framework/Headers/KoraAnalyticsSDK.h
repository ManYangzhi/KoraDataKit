//
//  KoraAnalyticsSDK.h
//  KoraSDK
//
//  Created by 杨志 on 2020/11/6.
//  Copyright © 2020 杨志. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KoraAnalyticsSDK : NSObject

+ (instancetype)sharedInstance;

- (instancetype)init NS_UNAVAILABLE;

// 当本地缓存的事件达到最大条数时，上传数据（默认50条）
@property (nonatomic, assign) NSInteger flushBulkSize;
// 两次数据发送的时间间隔
@property (nonatomic, assign) NSInteger flushInterval;
// 预置属性
@property (nonatomic, strong) NSDictionary<NSString *, id> *automaticProperties;
// 是否为被启动
@property (nonatomic, getter=isLaunchedPassively) BOOL launchedPassively;
// 设备id(匿名id) 优先级顺序:IDFA>IFDV>UUID
@property (nonatomic, copy) NSString *anonymousId;
// 登录id
@property (nonatomic, strong) NSString *loginId;
// 事件开始发生的时间戳
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSDictionary *> *trackTimer;
@property (nonatomic, weak) UIViewController *previousTrackViewController;

/**
 初始化SDK
 
 @param urlString 接受数据的服务端URL
 */
+ (void)startWithServerURL:(NSString *)urlString;

/**
 用户登录，设置登录ID
 @param loginId 用户登录id
 */
- (void)login:(NSString *)loginId;

/**
 向服务器同步本地所以数据
 */
- (void)flush;

- (void)printEvent:(NSDictionary *)event;

/**
* @abstract
* 调用 track 接口，追踪一个带有属性的 event
*
* @discussion
* propertyDict 是一个 Map。
* 其中的 key 是 Property 的名称，必须是 NSString
* value 则是 Property 的内容，只支持 NSString、NSNumber、NSSet、NSArray、NSDate 这些类型
* 特别的，NSSet 或者 NSArray 类型的 value 中目前只支持其中的元素是 NSString
*
* @param eventName      event的名称
* @param properties     event的属性
*/
- (void)track:(NSString *)eventName properties:(NSDictionary<NSString *, id> * _Nullable )properties;

@end

NS_ASSUME_NONNULL_END
