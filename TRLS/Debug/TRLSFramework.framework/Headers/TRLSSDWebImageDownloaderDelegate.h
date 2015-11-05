/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "TRLSSDWebImageCompat.h"

@class TRLSSDWebImageDownloader;

@protocol TRLSSDWebImageDownloaderDelegate <NSObject>

@optional

- (void)imageDownloaderDidFinish:(TRLSSDWebImageDownloader *)downloader;
- (void)imageDownloader:(TRLSSDWebImageDownloader *)downloader didFinishWithImage:(UIImage *)image;
- (void)imageDownloader:(TRLSSDWebImageDownloader *)downloader didFailWithError:(NSError *)error;

@end
