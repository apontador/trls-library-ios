/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * Created by james <https://github.com/mystcolor> on 9/28/11.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "TRLSSDWebImageCompat.h"

@protocol TRLSSDWebImageDecoderDelegate;

@interface TRLSSDWebImageDecoder : NSObject
{
    NSOperationQueue *imageDecodingQueue;
}

+ (TRLSSDWebImageDecoder *)sharedImageDecoder;
- (void)decodeImage:(UIImage *)image withDelegate:(id <TRLSSDWebImageDecoderDelegate>)delegate userInfo:(NSDictionary *)info;

@end

@protocol TRLSSDWebImageDecoderDelegate <NSObject>

- (void)imageDecoder:(TRLSSDWebImageDecoder *)decoder didFinishDecodingImage:(UIImage *)image userInfo:(NSDictionary *)userInfo;

@end

@interface UIImage (ForceDecode)

+ (UIImage *)decodedImageWithImage:(UIImage *)image;

@end