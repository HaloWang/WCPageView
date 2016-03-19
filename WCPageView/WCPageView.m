
#import "WCPageView.h"
#import <HaloObjC.h>

NSInteger const InfiniteNumberOfItems = 1000;

@interface WCPageView () <UICollectionViewDataSource>

@end

@implementation WCPageView

#pragma mark - Getter & Setter

- (void)setDelegate:(id<UICollectionViewDelegate>)delegate {
    _collectionView.delegate = delegate;
}

- (id<UICollectionViewDelegate>)delegate {
    return _collectionView.delegate;
}

- (CGFloat)collectionViewWidth {
    return _collectionView.frame.size.width;
}

- (void)setCurrentPageIndex:(NSInteger)currentPageIndex {
    
}

- (NSInteger)currentPageIndex {
    
    CGFloat adjustOffset = 0;
    switch (self.pageIndexChangePosition) {
        case WCPageViewCurrentPageIndexChangePositionHeader:
            adjustOffset = 0;
            break;
            
        case WCPageViewCurrentPageIndexChangePositionFooter:
            adjustOffset = -[self collectionViewWidth] / 2;
            break;
            
        case WCPageViewCurrentPageIndexChangePositionMiddle:
            adjustOffset = [self collectionViewWidth] / 2;
            break;
            
        default:
            break;
    }
    
    return (NSInteger)((_collectionView.contentOffset.x + adjustOffset)/ _collectionView.frame.size.width) % self.pageCount;
}

- (NSInteger)pageCount {
    return [self.dataSource numberOfItemsInPageView:self];
}

#pragma mark Init & Deinit

+ (WCPageView *)pageViewWithFrame:(CGRect)frame dataSource:(id<WCPageViewDataSource>)dataSource {
    return [[WCPageView alloc] initWithFrame:frame dataSource:dataSource];
}

- (instancetype)initWithFrame:(CGRect)frame dataSource:(id<WCPageViewDataSource>)dataSource {
    self = [super initWithFrame:frame];
    if (self) {
        
        _infinite = YES;
        _automaticallyPageControlCurrentPage = YES;
        _dataSource = dataSource;
        _pageIndexChangePosition = WCPageViewCurrentPageIndexChangePositionMiddle;
        CGSize _frameSize = frame.size;
        
        //  Set collectionViewLayout
        _layout                         = [UICollectionViewFlowLayout new];
        _layout.scrollDirection         = UICollectionViewScrollDirectionHorizontal;
        _layout.minimumInteritemSpacing = 0;
        _layout.minimumLineSpacing      = 0;
        _layout.itemSize                = frame.size;
        
        //  Set collectionView
        _collectionView = [[UICollectionView alloc]initWithFrame:CGRectMake(0, 0, _frameSize.width, _frameSize.height) collectionViewLayout:_layout];
        _collectionView.dataSource = self;
        _collectionView.pagingEnabled = true;
        _collectionView.showsHorizontalScrollIndicator = NO;
        _collectionView.backgroundColor = [UIColor clearColor];
        Class cellClass = [_dataSource collectionViewCellClassOfPageView:self];
        [_collectionView registerClass:cellClass forCellWithReuseIdentifier:NSStringFromClass(cellClass)];
        [self addSubview:_collectionView];
        
        //  Set pageControl
        _pageControl = [[UIPageControl alloc]init];
        _pageControl.frame = CGRectMake(0, frame.size.height - 30, frame.size.width, 30);
        _pageControl.numberOfPages = [self.dataSource numberOfItemsInPageView:self];
        [_pageControl addTarget:self action:@selector(pageControlValueChanged) forControlEvents:UIControlEventValueChanged];
        [self addSubview:_pageControl];
        
        //  Observe contentSize to change pageControl value
        [_collectionView addObserver:self forKeyPath:@"contentSize" options:NSKeyValueObservingOptionNew context:nil];
    }
    return self;
}

- (void)dealloc {
    [_collectionView removeObserver:self forKeyPath:@"contentSize"];
}

#pragma mark - Private Methods

- (void)pageControlValueChanged {
    
}

#pragma mark - KVO

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSString *,id> *)change context:(void *)context {
    if ([keyPath isEqualToString:@"contentSize"]) {
        
        if (self.automaticallyPageControlCurrentPage) {
            self.pageControl.currentPage = self.currentPageIndex;
        }
        
        if ([self.dataSource respondsToSelector:@selector(pageView:currentPageIndexChangeTo:)]) {
            [self.dataSource pageView:self currentPageIndexChangeTo:self.currentPageIndex];
        }
    }
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    if ([self isInfinite]) {
        return InfiniteNumberOfItems;
    }
    
    return self.pageCount;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    NSString *reuseIdentifier = NSStringFromClass([_dataSource collectionViewCellClassOfPageView:self]);
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier forIndexPath:indexPath];
    
    if ([self.dataSource respondsToSelector:@selector(pageView:configCell:atIndex:)]) {
        NSInteger index = indexPath.row % self.pageCount;
        [self.dataSource pageView:self configCell:cell atIndex:index];
    }
    
    return cell;
}

@end
