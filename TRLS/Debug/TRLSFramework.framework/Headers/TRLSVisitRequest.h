//
//  TRLSVisitContainer.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 08/12/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface TRLSVisitRequest : NSObject

- (id)initWithMethod:(NSString *)method json:(NSString *)json visit:(CLVisit *)visit;

@property (nonatomic, strong) NSString *method;
@property (nonatomic, strong) NSString *json;
@property (nonatomic, strong) CLVisit *visit;

@end