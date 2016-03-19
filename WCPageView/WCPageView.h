//
//  WCPageView.h
//  WCPageView
//
//  Created by 王策 on 16/3/19.
//  Copyright © 2016年 王策. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - Enumerations

/// 更换 currentPageIndex 的位置
typedef NS_ENUM(NSUInteger, WCPageViewCurrentPageIndexChangePosition) {
    /// 当下一页完全展示时更换 currentPageIndex
    WCPageViewCurrentPageIndexChangePositionHeader,
    /// 下一页展示了一半时更换 currentPageIndex
    WCPageViewCurrentPageIndexChangePositionMiddle,
    /// 下一页一旦展示就更换 currentPageIndex
    WCPageViewCurrentPageIndexChangePositionFooter,
};

#pragma mark - Delegate Declaration

@class WCPageView;
@protocol WCPageViewDataSource <NSObject>

@required
- (void)pageView:(nonnull WCPageView *)pageView configCell:(nonnull UICollectionViewCell *)cell atIndex:(NSInteger)index;
- (nonnull Class)collectionViewCellClassOfPageView:(nonnull WCPageView *)pageView;
- (NSInteger)numberOfItemsInPageView:(nonnull WCPageView *)pageView;

@optional
- (void)pageView:(nonnull WCPageView *)pageView currentPageIndexChangeTo:(NSInteger)currentPageIndex;

@end

@interface WCPageView : UIView

#pragma mark - Constructor & Required Properties

+ (nonnull WCPageView *)pageViewWithFrame:(CGRect)frame dataSource:(nonnull id<WCPageViewDataSource>)dataSource;

@property (nonatomic, weak) id<WCPageViewDataSource> dataSource;

#pragma mark - Page Settings

/// 设定该 PageView 是否可无限滚动，默认值为 YES
@property (nonatomic, assign, getter=isInfinite) BOOL infinite;
/// 需要展示的页面数量
@property (nonatomic, assign, readonly) NSInteger pageCount;

#pragma mark - Readonly Properties

@property (nonatomic, readonly, nonnull) UICollectionViewFlowLayout *layout;
@property (nonatomic, readonly, nonnull) UICollectionView *collectionView;

#pragma mark - UIPageControl

/// 你可以使用你自己的 pageControl
@property (nonatomic, strong, nullable) UIPageControl *pageControl;
/// 当前正在展示的页面 index
@property (nonatomic, assign) NSInteger currentPageIndex;
/// 自动设定 pageControl.currentPage，默认值为 YES
@property (nonatomic, assign) BOOL automaticallyPageControlCurrentPage;
/// pageIndex 改变位置，默认为 WCPageViewCurrentPageIndexChangePositionMiddle
@property (nonatomic, assign) WCPageViewCurrentPageIndexChangePosition pageIndexChangePosition;

#pragma mark - Timer

// TODO: ⚠️ Timer

@property (nonatomic, assign, getter=isTimerEnable) BOOL timerEnable;

@property (nonatomic, strong, nullable) NSTimer *timer;

@property (nonatomic, assign) NSTimeInterval frequency;
@property (nonatomic, assign) NSTimeInterval duration;
@property (nonatomic, assign) NSTimeInterval firstFireDelay;

@property (nonatomic, assign) BOOL animated;

@end
