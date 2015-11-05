/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

@class TRLSSDWebImageManager;
@class UIImage;

@protocol TRLSSDWebImageManagerDelegate <NSObject>

@optional

- (void)webImageManager:(TRLSSDWebImageManager *)imageManager didFinishWithImage:(UIImage *)image;
- (void)webImageManager:(TRLSSDWebImageManager *)imageManager didFailWithError:(NSError *)error;

@end
