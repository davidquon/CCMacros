//
//  CCMacros.h
//  
//
//  Created by James Womack on 8/16/11.
//
//  Copyright (c) 2011—2013 James J. Womack
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



#import <math.h>

#define RADIANS(__ANGLE__) ((__ANGLE__) / 180.0f * (float)M_PI)



#pragma mark -
#pragma mark TypeDefs

typedef BOOL boolean;
typedef NSString String;



#pragma mark -
#pragma mark Feature and platform detection

#ifndef __has_feature
    #define __has_feature(x) 0
#endif

#ifdef __OBJC_GC__
    #error CCJSONDataSource does not support Objective-C Garbage Collection
#endif

#define IF_PRE_IOS4(...) \
if (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iPhoneOS_4_0) \ { \
__VA_ARGS__ \
}



#pragma mark -
#pragma mark Strings

#define NSStringFromBOOL(aBool) String(@"%@", aBool?@"YES":@"NO")

#define String(fmt,...) [NSString stringWithFormat:fmt,__VA_ARGS__]

#define Append(appendTo,appendage) [appendTo stringByAppendingString:appendage]



#pragma mark -
#pragma mark Logging

#ifdef DEBUG
    #define DLog(...) NSLog(__VA_ARGS__)
    #define ILogPlus(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
    #define ILog(...) NSLog(@"%s [Line %d] ", __PRETTY_FUNCTION__, __LINE__);
#else
    #define DLog(...) /* */
    #define ILogPlus(...) /* */
    #define ILog(...) /* */
#endif

#define ALog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);



#pragma mark -
#pragma mark GCD

#define Once(foolMeOnce) \
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
foolMeOnce ;\
});

static dispatch_queue_t DispatchBG();
static dispatch_queue_t DispatchBG()
{
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
}

static dispatch_queue_t Dispatch();
static dispatch_queue_t Dispatch()
{
    return dispatch_get_main_queue();
}



#pragma mark -
#pragma mark Persistence

#define DEFAULTS [NSUserDefaults standardUserDefaults]



#pragma mark -
#pragma mark UIKit

#if __has_feature(objc_arc)
#define Alert(tag, title, msg, button, buttons...) {UIAlertView *__alert = [[UIAlertView alloc] initWithTitle:title message:msg delegate:self cancelButtonTitle:button otherButtonTitles:buttons];[__alert setTag:tag]; [__alert show];}
#define AlertND(tag, title, msg, button, buttons...) {UIAlertView *__alert = [[UIAlertView alloc] initWithTitle:title message:msg delegate:nil cancelButtonTitle:button otherButtonTitles:buttons];[__alert setTag:tag]; [__alert show];}
#else
#define Alert(tag, title, msg, button, buttons...) {UIAlertView *__alert = [[UIAlertView alloc] initWithTitle:title message:msg delegate:self cancelButtonTitle:button otherButtonTitles:buttons];[__alert setTag:tag]; [__alert show];[__alert release];}
#define AlertND(tag, title, msg, button, buttons...) {UIAlertView *__alert = [[UIAlertView alloc] initWithTitle:title message:msg delegate:nil cancelButtonTitle:button otherButtonTitles:buttons];[__alert setTag:tag]; [__alert show];[__alert release];}
#endif

#define MODAL_SAFELY_DISMISS_SELF (self.parentViewController==nil)?[self.presentingViewController dismissModalViewControllerAnimated:YES]:[self.parentViewController dismissModalViewControllerAnimated:YES]

#define BarBtnTitle(title,sel) [[[UIBarButtonItem alloc] initWithTitle:title style:UIBarButtonItemStyleBordered target:self action:sel] autorelease]

#define Img(name) [UIImage imageNamed:name]
#define ImgView(i) [[[UIImageView alloc] initWithImage:i] autorelease]

#define SCREENSIZE UIScreen.mainScreen.bounds.size



#pragma mark -
#pragma mark Colors

#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 \
alpha:(a)]

#define HSVCOLOR(h,s,v) [UIColor colorWithHue:(h) saturation:(s) value:(v) alpha:1]
#define HSVACOLOR(h,s,v,a) [UIColor colorWithHue:(h) saturation:(s) value:(v) alpha:(a)]

#define RGBA(r,g,b,a) (r)/255.0, (g)/255.0, (b)/255.0, (a)

// EXAMPLE: cell.textColor = HEXCOLOR(0xFF3366);
#define HEXCOLOR(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


// Copyright changes for all below this line
/*********************************************************************
 *  \author Kailoa Kadano
 *  \date 2006/3/23
 *  \brief Part of TouchSampleCode
 *  \copyright Copyright 2006-2009 6Tringle LLC. All rights reserved.
 */

#define NSYES [NSNumber numberWithBool:YES]
#define NSNO [NSNumber numberWithBool:NO]

#if !defined(DLOG)
#define DLOG(object)    (NSLog(@"" #object @" %d",object ));
#endif

#if !defined(FLOG)
#define FLOG(object)    (NSLog(@"" #object @" %f",object ));
#endif

#if !defined(OBJECT_LOG) //one argument
#define OBJECT_LOG(object)    (NSLog(@""  #object @" %@",[object description] ));
#endif

#if !defined(POINTLOG) //one argument
#define POINTLOG(point)    (NSLog(@""  #point @" x:%f y:%f", point.x, point.y ));
#endif

#if !defined(SIZELOG) //one argument
#define SIZELOG(size)    (NSLog(@""  #size @" width:%f height:%f", size.width, size.height ));
#endif

#if !defined(RECTLOG) //one argument
#define RECTLOG(rect)    (NSLog(@""  #rect @" x:%f y:%f w:%f h:%f", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height ));
#endif

#if !defined(SELECTOR_LOG) //No arguments
#define SELECTOR_LOG    (NSLog(@"%@ in %s", NSStringFromSelector(_cmd), __FILE__));
#endif

#if !defined(METHOD_LOG) //No arguments
#define METHOD_LOG    (NSLog(@"%@ %s\n%@", NSStringFromSelector(_cmd), __FILE__, self))
#endif

#if !defined(METHOD_LOG_THREAD) //No arguments
#define METHOD_LOG_THREAD    (NSLog(@"%@ %@ %s\n%@", NSStringFromSelector(_cmd), [NSThread currentThread], __FILE__, self))
#endif

#if !defined(NOT_NIL_ASSERT) //one argument
#define NOT_NIL_ASSERT(x)    NSAssert4((x != nil), @"\n\n    ****  Unexpected Nil Assertion  ****\n    ****  " #x @" is nil.\nin file:%s at line %i in Method %@ with object:\n %@", __FILE__, __LINE__, NSStringFromSelector(_cmd), self)
#endif

#if !defined(ALWAYS_ASSERT) //No arguments
#define ALWAYS_ASSERT    NSAssert4(0, @"\n\n    ****  Unexpected Assertion  **** \nAssertion in file:%s at line %i in Method %@ with object:\n %@", __FILE__, __LINE__, NSStringFromSelector(_cmd), self)
#endif

#if !defined(MSG_ASSERT) //one argument
#define MSG_ASSERT(x)    NSAssert5(0, @"\n\n    ****  Unexpected Assertion  **** \nReason: %@\nAssertion in file:%s at line %i in Method %@ with object:\n %@", x, __FILE__, __LINE__, NSStringFromSelector(_cmd), self)
#endif

#if !defined(ASSERT_TRUE) //one argument, if the argument is false, raise the assert
#define ASSERT_TRUE(test)    NSAssert4(test, @"\n\n    ****  Unexpected Assertion  **** \nAssertion in file:%s at line %i in Method %@ with object:\n %@", __FILE__, __LINE__, NSStringFromSelector(_cmd), self)
#endif

#if !defined(MSG_ASSERT_TRUE) //two arguments, if the argument is false, raise the assert and display the message
#define MSG_ASSERT_TRUE(test, msg)    NSAssert5(test, @"\n\n    ****  Unexpected Assertion  **** \nReason: %@\nAssertion in file:%s at line %i in Method %@ with object:\n %@", msg, __FILE__, __LINE__, NSStringFromSelector(_cmd), self)
#endif


