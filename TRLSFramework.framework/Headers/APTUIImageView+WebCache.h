//
//  APTUIImageView+WebCache.h
//  Apontador
//
//  Created by Tiago Pitteri on 5/10/12.
//  Copyright (c) 2012 Apontador. All rights reserved.
//

#import "SDWebImageCompat.h"
#import "SDWebImageManagerDelegate.h"
#import "SDWebImageManager.h"

@interface UIImageView (WebCache) <SDWebImageManagerDelegate>

- (void)addRoundedCorners:(CGFloat)radius borderColor:(UIColor *)borderColor borderWidh:(CGFloat)borderWidth;

- (void)setImageWithURL:(NSURL *)url indicator:(UIActivityIndicatorView *)indicator;

- (void)setImageWithURL:(NSURL *)url;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder indicator:(UIActivityIndicatorView *)indicator;

- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder indicator:(UIActivityIndicatorView *)indicator options:(SDWebImageOptions)options;

- (void)cancelCurrentImageLoad;

@end