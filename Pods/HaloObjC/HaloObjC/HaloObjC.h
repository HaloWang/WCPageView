//
//  HaloObjC.h
//  HaloObjC
//
//  Created by 王策 on 16/3/16.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - 固定尺寸
extern CGRect  ScreenBounds;
extern CGFloat ScreenWidth;
extern CGFloat ScreenHeight;
extern CGFloat NavigationBarHeight;
extern CGFloat TabBarHeight;
extern CGFloat StatusBarHeight;

#pragma mark - 沙盒路径
extern NSString *HomePath;
extern NSString *DocumentPath;
extern NSString *LibraryPath;
extern NSString *CachePath;
extern NSString *TempPath;

#pragma mark - Bundle
extern NSString *MainBundlePath;
extern NSString *ResourcePath;
extern NSString *ExecutablePath;

#pragma mark - 应用信息
extern NSString *AppBundleID;
extern NSString *AppVersion;
extern NSString *AppBuildVersion;

#pragma mark - 系统信息
extern NSString *SystemVersion;
extern float SystemVersionNumber;

#pragma mark - Measure

/**
 *  测量某段代码的执行时间
 *
 *  @param ^CodeWaitingForMeasure 你想测量的代码
 */
void measure(void(^CodeWaitingForMeasure)(void));

#pragma mark - Log

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print
 */
void cc(id obj);

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print with ✅
 */
void ccRight(id obj);

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print with ❌
 */
void ccError(id obj);

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print with ⚠️
 */
void ccWarning(id obj);

#pragma mark - HaloObjC

@interface HaloObjC : NSObject

/**
 *  开始服务
 */
+ (void)server;

/**
 *  是否开启 Log（也就是 ccLog），默认值是 YES
 */
+ (void)logEnable:(BOOL)enable;

@end

#pragma mark - UIView

@interface UIView (Halo)

/**
 *  设定圆角半径
 *
 *  @param radius 圆角半径
 */
- (void)cornerRadius:(CGFloat)radius;

/**
 *  同时设定 圆角半径 描边宽度 描边颜色
 *
 *  @param radius      圆角半径
 *  @param borderWidth 描边宽度
 *  @param borderColor 描边颜色
 */
- (void)cornerRadius:(CGFloat)radius borderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor;

@end

#pragma mark - UIColor

UIColor *ColorWithRGB(CGFloat r, CGFloat g, CGFloat b);
UIColor *ColorWithRGBA(CGFloat r, CGFloat g, CGFloat b, CGFloat a);

/**
 *  use hexValue like 0xFFFFFF to create a UIColor object
 */
UIColor *ColorWithHexValue(NSUInteger hexValue);
UIColor *ColorWithHexValueA(NSUInteger hexValue, CGFloat a);



