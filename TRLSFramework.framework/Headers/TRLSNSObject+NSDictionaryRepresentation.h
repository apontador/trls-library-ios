//
//  NSObject+NSDictionaryRepresentation.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (NSDictionaryRepresentation)

/**
 Returns an NSDictionary containing the properties of an object that are not nil.
 */
- (NSDictionary *)dictionaryRepresentation;

@end
