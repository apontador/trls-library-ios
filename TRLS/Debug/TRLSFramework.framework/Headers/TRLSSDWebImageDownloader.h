/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "TRLSSDWebImageDownloaderDelegate.h"
#import "TRLSSDWebImageCompat.h"

extern NSString *const TRLSSDWebImageDownloadStartNotification;
extern NSString *const TRLSSDWebImageDownloadStopNotification;

@interface TRLSSDWebImageDownloader : NSObject
{
    @private
    NSURL *url;
    id<TRLSSDWebImageDownloaderDelegate> delegate;
    NSURLConnection *connection;
    NSMutableData *imageData;
    id userInfo;
    BOOL lowPriority;
}

@property (nonatomic, retain) NSURL *url;
@property (nonatomic, retain) id<TRLSSDWebImageDownloaderDelegate> delegate;
@property (nonatomic, retain) NSMutableData *imageData;
@property (nonatomic, retain) id userInfo;
@property (nonatomic, readwrite) BOOL lowPriority;

+ (id)downloaderWithURL:(NSURL *)url delegate:(id<TRLSSDWebImageDownloaderDelegate>)delegate userInfo:(id)userInfo lowPriority:(BOOL)lowPriority;
+ (id)downloaderWithURL:(NSURL *)url delegate:(id<TRLSSDWebImageDownloaderDelegate>)delegate userInfo:(id)userInfo;
+ (id)downloaderWithURL:(NSURL *)url delegate:(id<TRLSSDWebImageDownloaderDelegate>)delegate;
- (void)start;
- (void)cancel;

// This method is now no-op and is deprecated
+ (void)setMaxConcurrentDownloads:(NSUInteger)max __attribute__((deprecated));

@end
