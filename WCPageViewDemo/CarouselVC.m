//
//  CarouselVC.m
//  WCPageViewDemo
//
//  Created by WangCe on 16/03/2017.
//  Copyright © 2017 王策. All rights reserved.
//

#import "CarouselVC.h"
#import <WCPageView/WCPageView.h>

@interface CarouselCell : UICollectionViewCell

@property (nonatomic, strong) UIImageView *imageView;

@end

@implementation CarouselCell

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.imageView = [UIImageView new];
    }
    return self;
}

@end

@interface CarouselVC () <WCPageViewDataSource>

@property (nonatomic, strong) NSArray<NSDictionary *>* data;

@end

@implementation CarouselVC

- (void)initData {
    self.data = @[@{},@{},@{},@{}];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    WCPageView *pageView = [WCPageView pageViewWithFrame:CGRectMake(0, 200, [UIScreen mainScreen].bounds.size.width, 200) dataSource:self];
    pageView.infinite = NO;
}

#pragma mark - WCPageViewDataSource

- (NSInteger)numberOfItemsInPageView:(WCPageView *)pageView {
    return self.data.count;
}

- (void)pageView:(WCPageView *)pageView configCell:(UICollectionViewCell *)cell atIndex:(NSInteger)index {
    cell.backgroundColor = [UIColor colorWithRed:0.5
                                           green:((CGFloat) index / self.data.count)
                                            blue:((CGFloat) index / self.data.count)
                                           alpha:1];
}

- (Class)collectionViewCellClassOfPageView:(WCPageView *)pageView {
    return [CarouselCell class];
}

@end
