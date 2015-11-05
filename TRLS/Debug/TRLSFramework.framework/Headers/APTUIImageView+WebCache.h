//
//  APTUIImageView+WebCache.h
//  Apontador
//
//  Created by Tiago Pitteri on 5/10/12.
//  Copyright (c) 2012 Apontador. All rights reserved.
//

#import "TRLSSDWebImageCompat.h"
#import "TRLSSDWebImageManagerDelegate.h"
#import "TRLSSDWebImageManager.h"

@interface UIImageView (WebCache) <TRLSSDWebImageManagerDelegate>

- (void)addRoundedCorners:(CGFloat)radius borderColor:(UIColor *)borderColor borderWidh:(CGFloat)borderWidth;

- (void)setImageWithURL:(NSURL *)url indicator:(UIActivityIndicatorView *)indicator;

- (void)setImageWithURL:(NSURL *)url;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder indicator:(UIActivityIndicatorView *)indicator;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder indicator:(UIActivityIndicatorView *)indicator options:(TRLSSDWebImageOptions)options;

- (void)cancelCurrentImageLoad;

@end