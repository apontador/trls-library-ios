/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "TRLSSDWebImageCompat.h"
#import "TRLSSDWebImageDownloaderDelegate.h"
#import "TRLSSDWebImageManagerDelegate.h"
#import "TRLSSDImageCacheDelegate.h"

typedef enum
{
    TRLSSDWebImageRetryFailed = 1 << 0,
    TRLSSDWebImageLowPriority = 1 << 1,
    TRLSSDWebImageCacheMemoryOnly = 1 << 2
} TRLSSDWebImageOptions;

@interface TRLSSDWebImageManager : NSObject <TRLSSDWebImageDownloaderDelegate, TRLSSDImageCacheDelegate>
{
    NSMutableArray *downloadDelegates;
    NSMutableArray *downloaders;
    NSMutableArray *cacheDelegates;
    NSMutableArray *cacheURLs;
    NSMutableDictionary *downloaderForURL;
    NSMutableArray *failedURLs;
}

@property (nonatomic, strong) UIActivityIndicatorView *indicator;

+ (id)sharedManager;
- (UIImage *)imageWithURL:(NSURL *)url;
- (void)downloadWithURL:(NSURL *)url delegate:(id<TRLSSDWebImageManagerDelegate>)delegate;
- (void)downloadWithURL:(NSURL *)url delegate:(id<TRLSSDWebImageManagerDelegate>)delegate options:(TRLSSDWebImageOptions)options;
- (void)downloadWithURL:(NSURL *)url delegate:(id<TRLSSDWebImageManagerDelegate>)delegate retryFailed:(BOOL)retryFailed __attribute__ ((deprecated)); // use options:TRLSSDWebImageRetryFailed instead
- (void)downloadWithURL:(NSURL *)url delegate:(id<TRLSSDWebImageManagerDelegate>)delegate retryFailed:(BOOL)retryFailed lowPriority:(BOOL)lowPriority __attribute__ ((deprecated)); // use options:TRLSSDWebImageRetryFailed|SDWebImageLowPriority instead
- (void)cancelForDelegate:(id<TRLSSDWebImageManagerDelegate>)delegate;

@end
