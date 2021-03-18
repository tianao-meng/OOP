; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.set = type opaque

@READ_INT_FAIL = constant i32 -2147483648, align 4
@READ_CHAR_FAIL = constant i8 0, align 1
@INVALID_SYMBOL = constant i32 0, align 4
@_tracing_out = internal global %struct._IO_FILE* null, align 8
@stderr = external global %struct._IO_FILE*, align 8
@.str = private unnamed_addr constant [28 x i8] c">>> cs136tools version 1.2\0A\00", align 1
@TRACE_FLAG = internal global i8 1, align 1
@stdout = external global %struct._IO_FILE*, align 8
@.str.1 = private unnamed_addr constant [19 x i8] c">>> [%s|%s|%d] >> \00", align 1
@.str.2 = private unnamed_addr constant [6 x i8] c"%s%s\0A\00", align 1
@.str.3 = private unnamed_addr constant [10 x i8] c"%s => %d\0A\00", align 1
@.str.4 = private unnamed_addr constant [10 x i8] c"%s => %c\0A\00", align 1
@.str.5 = private unnamed_addr constant [10 x i8] c"%s => %f\0A\00", align 1
@.str.6 = private unnamed_addr constant [10 x i8] c"%s => %s\0A\00", align 1
@.str.7 = private unnamed_addr constant [10 x i8] c"%s => %p\0A\00", align 1
@.str.8 = private unnamed_addr constant [20 x i8] c"trace_array_len > 0\00", align 1
@.str.9 = private unnamed_addr constant [49 x i8] c"/u1/dtompkins/.seashell/projects/_A7/q4/set-io.c\00", align 1
@__PRETTY_FUNCTION__._TRACE_ARR = private unnamed_addr constant [90 x i8] c"void _TRACE_ARR(const char *, const char *, void *, int, const char *, const char *, int)\00", align 1
@.str.10 = private unnamed_addr constant [16 x i8] c"trace_array_ptr\00", align 1
@.str.11 = private unnamed_addr constant [8 x i8] c"%s => [\00", align 1
@.str.12 = private unnamed_addr constant [3 x i8] c", \00", align 1
@.str.13 = private unnamed_addr constant [4 x i8] c"int\00", align 1
@.str.14 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.15 = private unnamed_addr constant [5 x i8] c"char\00", align 1
@.str.16 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.17 = private unnamed_addr constant [7 x i8] c"double\00", align 1
@.str.18 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@.str.19 = private unnamed_addr constant [5 x i8] c"bool\00", align 1
@.str.21 = private unnamed_addr constant [5 x i8] c"true\00", align 1
@.str.22 = private unnamed_addr constant [6 x i8] c"false\00", align 1
@.str.20 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@.str.23 = private unnamed_addr constant [7 x i8] c"symbol\00", align 1
@.str.24 = private unnamed_addr constant [19 x i8] c"INVALID TYPE: %s]\0A\00", align 1
@.str.25 = private unnamed_addr constant [3 x i8] c"]\0A\00", align 1
@_num_symbols = internal global i32 0, align 4
@_symbol_table = internal global <{ [64 x i8], [255 x [64 x i8]] }> <{ [64 x i8] c"INVALID_SYMBOL\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00", [255 x [64 x i8]] zeroinitializer }>, align 16
@.str.26 = private unnamed_addr constant [4 x i8] c" %c\00", align 1
@_symbol_buffer = internal global [64 x i8] zeroinitializer, align 16
@.str.27 = private unnamed_addr constant [16 x i8] c"invalid command\00", align 1
@.str.28 = private unnamed_addr constant [6 x i8] c"empty\00", align 1
@.str.29 = private unnamed_addr constant [32 x i8] c"set identifier already assigned\00", align 1
@.str.30 = private unnamed_addr constant [7 x i8] c"single\00", align 1
@.str.31 = private unnamed_addr constant [7 x i8] c"create\00", align 1
@.str.32 = private unnamed_addr constant [21 x i8] c"invalid array length\00", align 1
@.str.33 = private unnamed_addr constant [5 x i8] c"card\00", align 1
@.str.34 = private unnamed_addr constant [19 x i8] c"set does not exist\00", align 1
@.str.35 = private unnamed_addr constant [11 x i8] c"|%c| = %d\0A\00", align 1
@.str.36 = private unnamed_addr constant [7 x i8] c"member\00", align 1
@.str.37 = private unnamed_addr constant [10 x i8] c"%d in %c\0A\00", align 1
@.str.38 = private unnamed_addr constant [14 x i8] c"%d not in %c\0A\00", align 1
@.str.39 = private unnamed_addr constant [3 x i8] c"eq\00", align 1
@.str.40 = private unnamed_addr constant [10 x i8] c"%c == %c\0A\00", align 1
@.str.41 = private unnamed_addr constant [10 x i8] c"%c != %c\0A\00", align 1
@.str.42 = private unnamed_addr constant [6 x i8] c"union\00", align 1
@.str.43 = private unnamed_addr constant [10 x i8] c"intersect\00", align 1
@.str.44 = private unnamed_addr constant [5 x i8] c"diff\00", align 1
@.str.45 = private unnamed_addr constant [6 x i8] c"print\00", align 1
@.str.46 = private unnamed_addr constant [5 x i8] c"%c: \00", align 1
@.str.47 = private unnamed_addr constant [8 x i8] c"destroy\00", align 1
@.str.48 = private unnamed_addr constant [5 x i8] c"quit\00", align 1
@.str.49 = private unnamed_addr constant [16 x i8] c"unknown command\00", align 1
@.str.53 = private unnamed_addr constant [12 x i8] c"invalid INT\00", align 1
@.str.52 = private unnamed_addr constant [23 x i8] c"invalid set identifier\00", align 1
@.str.51 = private unnamed_addr constant [12 x i8] c"ERROR [%s]\0A\00", align 1

; Function Attrs: noinline nounwind optnone
define void @trace_version() #0 {
entry:
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %call = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([28 x i8], [28 x i8]* @.str, i32 0, i32 0))
  ret void
}

declare i32 @fprintf(%struct._IO_FILE*, i8*, ...) #1

; Function Attrs: noinline nounwind optnone
define void @trace_off() #0 {
entry:
  store i8 0, i8* @TRACE_FLAG, align 1
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @trace_sync() #0 {
entry:
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @stdout, align 8
  store %struct._IO_FILE* %0, %struct._IO_FILE** @_tracing_out, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @_TRACE_MSG(i8* %expstr, i8* %expval, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %expstr.addr = alloca i8*, align 8
  %expval.addr = alloca i8*, align 8
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  store i8* %expstr, i8** %expstr.addr, align 8
  store i8* %expval, i8** %expval.addr, align 8
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end5

if.then2:                                         ; preds = %if.end
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %4 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %4, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %5 = load i8*, i8** %funcname.addr, align 8
  %6 = load i32, i32* %lineno.addr, align 4
  %call3 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %5, i32 %6)
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %8 = load i8*, i8** %expstr.addr, align 8
  %9 = load i8*, i8** %expval.addr, align 8
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %7, i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.2, i32 0, i32 0), i8* %8, i8* %9)
  br label %if.end5

if.end5:                                          ; preds = %if.then2, %if.end
  ret void
}

; Function Attrs: nounwind readonly
declare i8* @strrchr(i8*, i32) #2

; Function Attrs: noinline nounwind optnone
define void @_TRACE_INT(i8* %expstr, i32 %expval, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %expstr.addr = alloca i8*, align 8
  %expval.addr = alloca i32, align 4
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  store i8* %expstr, i8** %expstr.addr, align 8
  store i32 %expval, i32* %expval.addr, align 4
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end5

if.then2:                                         ; preds = %if.end
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %4 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %4, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %5 = load i8*, i8** %funcname.addr, align 8
  %6 = load i32, i32* %lineno.addr, align 4
  %call3 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %5, i32 %6)
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %8 = load i8*, i8** %expstr.addr, align 8
  %9 = load i32, i32* %expval.addr, align 4
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %7, i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.3, i32 0, i32 0), i8* %8, i32 %9)
  br label %if.end5

if.end5:                                          ; preds = %if.then2, %if.end
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @_TRACE_CHAR(i8* %expstr, i8 signext %expval, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %expstr.addr = alloca i8*, align 8
  %expval.addr = alloca i8, align 1
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  store i8* %expstr, i8** %expstr.addr, align 8
  store i8 %expval, i8* %expval.addr, align 1
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end5

if.then2:                                         ; preds = %if.end
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %4 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %4, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %5 = load i8*, i8** %funcname.addr, align 8
  %6 = load i32, i32* %lineno.addr, align 4
  %call3 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %5, i32 %6)
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %8 = load i8*, i8** %expstr.addr, align 8
  %9 = load i8, i8* %expval.addr, align 1
  %conv = sext i8 %9 to i32
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %7, i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.4, i32 0, i32 0), i8* %8, i32 %conv)
  br label %if.end5

if.end5:                                          ; preds = %if.then2, %if.end
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @_TRACE_DOUBLE(i8* %expstr, double %expval, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %expstr.addr = alloca i8*, align 8
  %expval.addr = alloca double, align 8
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  store i8* %expstr, i8** %expstr.addr, align 8
  store double %expval, double* %expval.addr, align 8
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end5

if.then2:                                         ; preds = %if.end
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %4 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %4, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %5 = load i8*, i8** %funcname.addr, align 8
  %6 = load i32, i32* %lineno.addr, align 4
  %call3 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %5, i32 %6)
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %8 = load i8*, i8** %expstr.addr, align 8
  %9 = load double, double* %expval.addr, align 8
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %7, i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.5, i32 0, i32 0), i8* %8, double %9)
  br label %if.end5

if.end5:                                          ; preds = %if.then2, %if.end
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @_TRACE_STRING(i8* %expstr, i8* %expval, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %expstr.addr = alloca i8*, align 8
  %expval.addr = alloca i8*, align 8
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  store i8* %expstr, i8** %expstr.addr, align 8
  store i8* %expval, i8** %expval.addr, align 8
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end5

if.then2:                                         ; preds = %if.end
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %4 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %4, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %5 = load i8*, i8** %funcname.addr, align 8
  %6 = load i32, i32* %lineno.addr, align 4
  %call3 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %5, i32 %6)
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %8 = load i8*, i8** %expstr.addr, align 8
  %9 = load i8*, i8** %expval.addr, align 8
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %7, i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.6, i32 0, i32 0), i8* %8, i8* %9)
  br label %if.end5

if.end5:                                          ; preds = %if.then2, %if.end
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @_TRACE_SYMBOL(i8* %expstr, i8* %expval, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %expstr.addr = alloca i8*, align 8
  %expval.addr = alloca i8*, align 8
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  store i8* %expstr, i8** %expstr.addr, align 8
  store i8* %expval, i8** %expval.addr, align 8
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end5

if.then2:                                         ; preds = %if.end
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %4 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %4, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %5 = load i8*, i8** %funcname.addr, align 8
  %6 = load i32, i32* %lineno.addr, align 4
  %call3 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %5, i32 %6)
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %8 = load i8*, i8** %expstr.addr, align 8
  %9 = load i8*, i8** %expval.addr, align 8
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %7, i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.6, i32 0, i32 0), i8* %8, i8* %9)
  br label %if.end5

if.end5:                                          ; preds = %if.then2, %if.end
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @_TRACE_PTR(i8* %expstr, i8* %expval, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %expstr.addr = alloca i8*, align 8
  %expval.addr = alloca i8*, align 8
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  store i8* %expstr, i8** %expstr.addr, align 8
  store i8* %expval, i8** %expval.addr, align 8
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end5

if.then2:                                         ; preds = %if.end
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %4 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %4, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %5 = load i8*, i8** %funcname.addr, align 8
  %6 = load i32, i32* %lineno.addr, align 4
  %call3 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %5, i32 %6)
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %8 = load i8*, i8** %expstr.addr, align 8
  %9 = load i8*, i8** %expval.addr, align 8
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %7, i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.7, i32 0, i32 0), i8* %8, i8* %9)
  br label %if.end5

if.end5:                                          ; preds = %if.then2, %if.end
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @_TRACE_ARR(i8* %type, i8* %expstr, i8* %trace_array_ptr, i32 %trace_array_len, i8* %filename, i8* %funcname, i32 %lineno) #0 {
entry:
  %type.addr = alloca i8*, align 8
  %expstr.addr = alloca i8*, align 8
  %trace_array_ptr.addr = alloca i8*, align 8
  %trace_array_len.addr = alloca i32, align 4
  %filename.addr = alloca i8*, align 8
  %funcname.addr = alloca i8*, align 8
  %lineno.addr = alloca i32, align 4
  %i = alloca i32, align 4
  store i8* %type, i8** %type.addr, align 8
  store i8* %expstr, i8** %expstr.addr, align 8
  store i8* %trace_array_ptr, i8** %trace_array_ptr.addr, align 8
  store i32 %trace_array_len, i32* %trace_array_len.addr, align 4
  store i8* %filename, i8** %filename.addr, align 8
  store i8* %funcname, i8** %funcname.addr, align 8
  store i32 %lineno, i32* %lineno.addr, align 4
  %0 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %tobool = icmp ne %struct._IO_FILE* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** @_tracing_out, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i8, i8* @TRACE_FLAG, align 1
  %tobool1 = trunc i8 %2 to i1
  br i1 %tobool1, label %if.then2, label %if.end59

if.then2:                                         ; preds = %if.end
  %3 = load i32, i32* %trace_array_len.addr, align 4
  %cmp = icmp sgt i32 %3, 0
  br i1 %cmp, label %if.then3, label %if.else

if.then3:                                         ; preds = %if.then2
  br label %if.end4

if.else:                                          ; preds = %if.then2
  call void @__assert_fail(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.str.8, i32 0, i32 0), i8* getelementptr inbounds ([49 x i8], [49 x i8]* @.str.9, i32 0, i32 0), i32 58, i8* getelementptr inbounds ([90 x i8], [90 x i8]* @__PRETTY_FUNCTION__._TRACE_ARR, i32 0, i32 0)) #7
  unreachable

if.end4:                                          ; preds = %if.then3
  %4 = load i8*, i8** %trace_array_ptr.addr, align 8
  %tobool5 = icmp ne i8* %4, null
  br i1 %tobool5, label %if.then6, label %if.else7

if.then6:                                         ; preds = %if.end4
  br label %if.end8

if.else7:                                         ; preds = %if.end4
  call void @__assert_fail(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.10, i32 0, i32 0), i8* getelementptr inbounds ([49 x i8], [49 x i8]* @.str.9, i32 0, i32 0), i32 59, i8* getelementptr inbounds ([90 x i8], [90 x i8]* @__PRETTY_FUNCTION__._TRACE_ARR, i32 0, i32 0)) #7
  unreachable

if.end8:                                          ; preds = %if.then6
  %5 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %6 = load i8*, i8** %filename.addr, align 8
  %call = call i8* @strrchr(i8* %6, i32 47) #6
  %add.ptr = getelementptr inbounds i8, i8* %call, i64 1
  %7 = load i8*, i8** %funcname.addr, align 8
  %8 = load i32, i32* %lineno.addr, align 4
  %call9 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %5, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0), i8* %add.ptr, i8* %7, i32 %8)
  %9 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %10 = load i8*, i8** %expstr.addr, align 8
  %call10 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %9, i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.11, i32 0, i32 0), i8* %10)
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end8
  %11 = load i32, i32* %i, align 4
  %12 = load i32, i32* %trace_array_len.addr, align 4
  %cmp11 = icmp slt i32 %11, %12
  br i1 %cmp11, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %13 = load i32, i32* %i, align 4
  %tobool12 = icmp ne i32 %13, 0
  br i1 %tobool12, label %if.then13, label %if.end15

if.then13:                                        ; preds = %for.body
  %14 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %call14 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %14, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.12, i32 0, i32 0))
  br label %if.end15

if.end15:                                         ; preds = %if.then13, %for.body
  %15 = load i8*, i8** %type.addr, align 8
  %call16 = call i32 @strcmp(i8* %15, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.13, i32 0, i32 0)) #6
  %tobool17 = icmp ne i32 %call16, 0
  br i1 %tobool17, label %if.else20, label %if.then18

if.then18:                                        ; preds = %if.end15
  %16 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %17 = load i8*, i8** %trace_array_ptr.addr, align 8
  %18 = bitcast i8* %17 to i32*
  %19 = load i32, i32* %i, align 4
  %idxprom = sext i32 %19 to i64
  %arrayidx = getelementptr inbounds i32, i32* %18, i64 %idxprom
  %20 = load i32, i32* %arrayidx, align 4
  %call19 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %16, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.14, i32 0, i32 0), i32 %20)
  br label %if.end57

if.else20:                                        ; preds = %if.end15
  %21 = load i8*, i8** %type.addr, align 8
  %call21 = call i32 @strcmp(i8* %21, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.15, i32 0, i32 0)) #6
  %tobool22 = icmp ne i32 %call21, 0
  br i1 %tobool22, label %if.else27, label %if.then23

if.then23:                                        ; preds = %if.else20
  %22 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %23 = load i8*, i8** %trace_array_ptr.addr, align 8
  %24 = load i32, i32* %i, align 4
  %idxprom24 = sext i32 %24 to i64
  %arrayidx25 = getelementptr inbounds i8, i8* %23, i64 %idxprom24
  %25 = load i8, i8* %arrayidx25, align 1
  %conv = sext i8 %25 to i32
  %call26 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %22, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.16, i32 0, i32 0), i32 %conv)
  br label %if.end56

if.else27:                                        ; preds = %if.else20
  %26 = load i8*, i8** %type.addr, align 8
  %call28 = call i32 @strcmp(i8* %26, i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.17, i32 0, i32 0)) #6
  %tobool29 = icmp ne i32 %call28, 0
  br i1 %tobool29, label %if.else34, label %if.then30

if.then30:                                        ; preds = %if.else27
  %27 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %28 = load i8*, i8** %trace_array_ptr.addr, align 8
  %29 = bitcast i8* %28 to double*
  %30 = load i32, i32* %i, align 4
  %idxprom31 = sext i32 %30 to i64
  %arrayidx32 = getelementptr inbounds double, double* %29, i64 %idxprom31
  %31 = load double, double* %arrayidx32, align 8
  %call33 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %27, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.18, i32 0, i32 0), double %31)
  br label %if.end55

if.else34:                                        ; preds = %if.else27
  %32 = load i8*, i8** %type.addr, align 8
  %call35 = call i32 @strcmp(i8* %32, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.19, i32 0, i32 0)) #6
  %tobool36 = icmp ne i32 %call35, 0
  br i1 %tobool36, label %if.else43, label %if.then37

if.then37:                                        ; preds = %if.else34
  %33 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %34 = load i8*, i8** %trace_array_ptr.addr, align 8
  %35 = load i32, i32* %i, align 4
  %idxprom38 = sext i32 %35 to i64
  %arrayidx39 = getelementptr inbounds i8, i8* %34, i64 %idxprom38
  %36 = load i8, i8* %arrayidx39, align 1
  %tobool40 = trunc i8 %36 to i1
  %37 = zext i1 %tobool40 to i64
  %cond = select i1 %tobool40, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.21, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.22, i32 0, i32 0)
  %call42 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %33, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.20, i32 0, i32 0), i8* %cond)
  br label %if.end54

if.else43:                                        ; preds = %if.else34
  %38 = load i8*, i8** %type.addr, align 8
  %call44 = call i32 @strcmp(i8* %38, i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.23, i32 0, i32 0)) #6
  %tobool45 = icmp ne i32 %call44, 0
  br i1 %tobool45, label %if.else51, label %if.then46

if.then46:                                        ; preds = %if.else43
  %39 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %40 = load i8*, i8** %trace_array_ptr.addr, align 8
  %41 = bitcast i8* %40 to i32*
  %42 = load i32, i32* %i, align 4
  %idxprom47 = sext i32 %42 to i64
  %arrayidx48 = getelementptr inbounds i32, i32* %41, i64 %idxprom47
  %43 = load i32, i32* %arrayidx48, align 4
  %call49 = call i8* @_SYM(i32 %43)
  %call50 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %39, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.20, i32 0, i32 0), i8* %call49)
  br label %if.end53

if.else51:                                        ; preds = %if.else43
  %44 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %45 = load i8*, i8** %type.addr, align 8
  %call52 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %44, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.24, i32 0, i32 0), i8* %45)
  br label %if.end59

if.end53:                                         ; preds = %if.then46
  br label %if.end54

if.end54:                                         ; preds = %if.end53, %if.then37
  br label %if.end55

if.end55:                                         ; preds = %if.end54, %if.then30
  br label %if.end56

if.end56:                                         ; preds = %if.end55, %if.then23
  br label %if.end57

if.end57:                                         ; preds = %if.end56, %if.then18
  br label %for.inc

for.inc:                                          ; preds = %if.end57
  %46 = load i32, i32* %i, align 4
  %inc = add nsw i32 %46, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %47 = load %struct._IO_FILE*, %struct._IO_FILE** @_tracing_out, align 8
  %call58 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %47, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.25, i32 0, i32 0))
  br label %if.end59

if.end59:                                         ; preds = %if.else51, %for.end, %if.end
  ret void
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #3

; Function Attrs: nounwind readonly
declare i32 @strcmp(i8*, i8*) #2

; Function Attrs: noinline nounwind optnone
define i8* @_SYM(i32 %symbol_id) #0 {
entry:
  %symbol_id.addr = alloca i32, align 4
  store i32 %symbol_id, i32* %symbol_id.addr, align 4
  %0 = load i32, i32* %symbol_id.addr, align 4
  %cmp = icmp slt i32 %0, 0
  br i1 %cmp, label %if.then, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %entry
  %1 = load i32, i32* %symbol_id.addr, align 4
  %2 = load i32, i32* @_num_symbols, align 4
  %cmp1 = icmp sgt i32 %1, %2
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %lor.lhs.false, %entry
  store i32 0, i32* %symbol_id.addr, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %lor.lhs.false
  %3 = load i32, i32* %symbol_id.addr, align 4
  %idxprom = sext i32 %3 to i64
  %arrayidx = getelementptr inbounds [256 x [64 x i8]], [256 x [64 x i8]]* bitcast (<{ [64 x i8], [255 x [64 x i8]] }>* @_symbol_table to [256 x [64 x i8]]*), i64 0, i64 %idxprom
  %arraydecay = getelementptr inbounds [64 x i8], [64 x i8]* %arrayidx, i32 0, i32 0
  ret i8* %arraydecay
}

; Function Attrs: noinline nounwind optnone
define i32 @read_int() #0 {
entry:
  %retval = alloca i32, align 4
  %i = alloca i32, align 4
  %result = alloca i32, align 4
  %call = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.14, i32 0, i32 0), i32* %i)
  store i32 %call, i32* %result, align 4
  %0 = load i32, i32* %result, align 4
  %cmp = icmp ne i32 %0, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 -2147483648, i32* %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %1 = load i32, i32* %i, align 4
  store i32 %1, i32* %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %2 = load i32, i32* %retval, align 4
  ret i32 %2
}

declare i32 @__isoc99_scanf(i8*, ...) #1

; Function Attrs: noinline nounwind optnone
define signext i8 @read_char(i1 zeroext %ignore_ws) #0 {
entry:
  %retval = alloca i8, align 1
  %ignore_ws.addr = alloca i8, align 1
  %c = alloca i8, align 1
  %result = alloca i32, align 4
  %frombool = zext i1 %ignore_ws to i8
  store i8 %frombool, i8* %ignore_ws.addr, align 1
  store i8 0, i8* %c, align 1
  %0 = load i8, i8* %ignore_ws.addr, align 1
  %tobool = trunc i8 %0 to i1
  %1 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.26, i32 0, i32 0), i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.16, i32 0, i32 0)
  %call = call i32 (i8*, ...) @__isoc99_scanf(i8* %cond, i8* %c)
  store i32 %call, i32* %result, align 4
  %2 = load i32, i32* %result, align 4
  %cmp = icmp ne i32 %2, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval, align 1
  br label %return

if.end:                                           ; preds = %entry
  %3 = load i8, i8* %c, align 1
  %conv = sext i8 %3 to i32
  %cmp1 = icmp eq i32 %conv, 10
  br i1 %cmp1, label %if.then9, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %if.end
  %4 = load i8, i8* %c, align 1
  %conv3 = sext i8 %4 to i32
  %cmp4 = icmp sle i32 32, %conv3
  br i1 %cmp4, label %land.lhs.true, label %if.end10

land.lhs.true:                                    ; preds = %lor.lhs.false
  %5 = load i8, i8* %c, align 1
  %conv6 = sext i8 %5 to i32
  %cmp7 = icmp sle i32 %conv6, 126
  br i1 %cmp7, label %if.then9, label %if.end10

if.then9:                                         ; preds = %land.lhs.true, %if.end
  %6 = load i8, i8* %c, align 1
  store i8 %6, i8* %retval, align 1
  br label %return

if.end10:                                         ; preds = %land.lhs.true, %lor.lhs.false
  store i8 0, i8* %retval, align 1
  br label %return

return:                                           ; preds = %if.end10, %if.then9, %if.then
  %7 = load i8, i8* %retval, align 1
  ret i8 %7
}

; Function Attrs: noinline nounwind optnone
define i32 @lookup_symbol(i8* %symbol_string) #0 {
entry:
  %retval = alloca i32, align 4
  %symbol_string.addr = alloca i8*, align 8
  store i8* %symbol_string, i8** %symbol_string.addr, align 8
  %0 = load i8*, i8** %symbol_string.addr, align 8
  %call = call zeroext i1 @_valid_symbol(i8* %0)
  br i1 %call, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %1 = load i8*, i8** %symbol_string.addr, align 8
  %call1 = call i32 @_lookup_add(i8* %1)
  store i32 %call1, i32* %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %2 = load i32, i32* %retval, align 4
  ret i32 %2
}

; Function Attrs: noinline nounwind optnone
define internal zeroext i1 @_valid_symbol(i8* %s) #0 {
entry:
  %retval = alloca i1, align 1
  %s.addr = alloca i8*, align 8
  %len = alloca i32, align 4
  %i = alloca i32, align 4
  store i8* %s, i8** %s.addr, align 8
  %0 = load i8*, i8** %s.addr, align 8
  %call = call i64 @strlen(i8* %0) #6
  %conv = trunc i64 %call to i32
  store i32 %conv, i32* %len, align 4
  %1 = load i32, i32* %len, align 4
  %cmp = icmp eq i32 %1, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval, align 1
  br label %return

if.end:                                           ; preds = %entry
  %2 = load i32, i32* %len, align 4
  %cmp2 = icmp sge i32 %2, 64
  br i1 %cmp2, label %if.then4, label %if.end5

if.then4:                                         ; preds = %if.end
  store i1 false, i1* %retval, align 1
  br label %return

if.end5:                                          ; preds = %if.end
  %3 = load i8*, i8** %s.addr, align 8
  %arrayidx = getelementptr inbounds i8, i8* %3, i64 0
  %4 = load i8, i8* %arrayidx, align 1
  %conv6 = sext i8 %4 to i32
  %call7 = call i32 @toupper(i32 %conv6) #6
  %cmp8 = icmp slt i32 %call7, 65
  br i1 %cmp8, label %if.then15, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %if.end5
  %5 = load i8*, i8** %s.addr, align 8
  %arrayidx10 = getelementptr inbounds i8, i8* %5, i64 0
  %6 = load i8, i8* %arrayidx10, align 1
  %conv11 = sext i8 %6 to i32
  %call12 = call i32 @toupper(i32 %conv11) #6
  %cmp13 = icmp sgt i32 %call12, 90
  br i1 %cmp13, label %if.then15, label %if.end16

if.then15:                                        ; preds = %lor.lhs.false, %if.end5
  store i1 false, i1* %retval, align 1
  br label %return

if.end16:                                         ; preds = %lor.lhs.false
  store i32 1, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end16
  %7 = load i32, i32* %i, align 4
  %8 = load i32, i32* %len, align 4
  %cmp17 = icmp slt i32 %7, %8
  br i1 %cmp17, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %9 = load i8*, i8** %s.addr, align 8
  %10 = load i32, i32* %i, align 4
  %idxprom = sext i32 %10 to i64
  %arrayidx19 = getelementptr inbounds i8, i8* %9, i64 %idxprom
  %11 = load i8, i8* %arrayidx19, align 1
  %conv20 = sext i8 %11 to i32
  %call21 = call i32 @toupper(i32 %conv20) #6
  %cmp22 = icmp sge i32 %call21, 65
  br i1 %cmp22, label %land.lhs.true, label %land.lhs.true30

land.lhs.true:                                    ; preds = %for.body
  %12 = load i8*, i8** %s.addr, align 8
  %13 = load i32, i32* %i, align 4
  %idxprom24 = sext i32 %13 to i64
  %arrayidx25 = getelementptr inbounds i8, i8* %12, i64 %idxprom24
  %14 = load i8, i8* %arrayidx25, align 1
  %conv26 = sext i8 %14 to i32
  %call27 = call i32 @toupper(i32 %conv26) #6
  %cmp28 = icmp sle i32 %call27, 90
  br i1 %cmp28, label %if.end49, label %land.lhs.true30

land.lhs.true30:                                  ; preds = %land.lhs.true, %for.body
  %15 = load i8*, i8** %s.addr, align 8
  %16 = load i32, i32* %i, align 4
  %idxprom31 = sext i32 %16 to i64
  %arrayidx32 = getelementptr inbounds i8, i8* %15, i64 %idxprom31
  %17 = load i8, i8* %arrayidx32, align 1
  %conv33 = sext i8 %17 to i32
  %cmp34 = icmp sge i32 %conv33, 48
  br i1 %cmp34, label %land.lhs.true36, label %land.lhs.true42

land.lhs.true36:                                  ; preds = %land.lhs.true30
  %18 = load i8*, i8** %s.addr, align 8
  %19 = load i32, i32* %i, align 4
  %idxprom37 = sext i32 %19 to i64
  %arrayidx38 = getelementptr inbounds i8, i8* %18, i64 %idxprom37
  %20 = load i8, i8* %arrayidx38, align 1
  %conv39 = sext i8 %20 to i32
  %cmp40 = icmp sle i32 %conv39, 57
  br i1 %cmp40, label %if.end49, label %land.lhs.true42

land.lhs.true42:                                  ; preds = %land.lhs.true36, %land.lhs.true30
  %21 = load i8*, i8** %s.addr, align 8
  %22 = load i32, i32* %i, align 4
  %idxprom43 = sext i32 %22 to i64
  %arrayidx44 = getelementptr inbounds i8, i8* %21, i64 %idxprom43
  %23 = load i8, i8* %arrayidx44, align 1
  %conv45 = sext i8 %23 to i32
  %cmp46 = icmp eq i32 %conv45, 95
  br i1 %cmp46, label %if.end49, label %if.then48

if.then48:                                        ; preds = %land.lhs.true42
  store i1 false, i1* %retval, align 1
  br label %return

if.end49:                                         ; preds = %land.lhs.true42, %land.lhs.true36, %land.lhs.true
  br label %for.inc

for.inc:                                          ; preds = %if.end49
  %24 = load i32, i32* %i, align 4
  %inc = add nsw i32 %24, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  store i1 true, i1* %retval, align 1
  br label %return

return:                                           ; preds = %for.end, %if.then48, %if.then15, %if.then4, %if.then
  %25 = load i1, i1* %retval, align 1
  ret i1 %25
}

; Function Attrs: noinline nounwind optnone
define internal i32 @_lookup_add(i8* %s) #0 {
entry:
  %retval = alloca i32, align 4
  %s.addr = alloca i8*, align 8
  %i = alloca i32, align 4
  store i8* %s, i8** %s.addr, align 8
  store i32 1, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, i32* %i, align 4
  %1 = load i32, i32* @_num_symbols, align 4
  %cmp = icmp sle i32 %0, %1
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %2 = load i8*, i8** %s.addr, align 8
  %3 = load i32, i32* %i, align 4
  %idxprom = sext i32 %3 to i64
  %arrayidx = getelementptr inbounds [256 x [64 x i8]], [256 x [64 x i8]]* bitcast (<{ [64 x i8], [255 x [64 x i8]] }>* @_symbol_table to [256 x [64 x i8]]*), i64 0, i64 %idxprom
  %arraydecay = getelementptr inbounds [64 x i8], [64 x i8]* %arrayidx, i32 0, i32 0
  %call = call i32 @strcmp(i8* %2, i8* %arraydecay) #6
  %tobool = icmp ne i32 %call, 0
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %for.body
  %4 = load i32, i32* %i, align 4
  store i32 %4, i32* %retval, align 4
  br label %return

if.end:                                           ; preds = %for.body
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %5 = load i32, i32* %i, align 4
  %inc = add nsw i32 %5, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %6 = load i32, i32* @_num_symbols, align 4
  %add = add nsw i32 %6, 1
  %cmp1 = icmp eq i32 %add, 256
  br i1 %cmp1, label %if.then2, label %if.end3

if.then2:                                         ; preds = %for.end
  store i32 0, i32* %retval, align 4
  br label %return

if.end3:                                          ; preds = %for.end
  %7 = load i32, i32* @_num_symbols, align 4
  %inc4 = add nsw i32 %7, 1
  store i32 %inc4, i32* @_num_symbols, align 4
  %8 = load i32, i32* @_num_symbols, align 4
  %idxprom5 = sext i32 %8 to i64
  %arrayidx6 = getelementptr inbounds [256 x [64 x i8]], [256 x [64 x i8]]* bitcast (<{ [64 x i8], [255 x [64 x i8]] }>* @_symbol_table to [256 x [64 x i8]]*), i64 0, i64 %idxprom5
  %arraydecay7 = getelementptr inbounds [64 x i8], [64 x i8]* %arrayidx6, i32 0, i32 0
  %9 = load i8*, i8** %s.addr, align 8
  %call8 = call i8* @strcpy(i8* %arraydecay7, i8* %9) #8
  %10 = load i32, i32* @_num_symbols, align 4
  store i32 %10, i32* %retval, align 4
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %11 = load i32, i32* %retval, align 4
  ret i32 %11
}

; Function Attrs: nounwind
declare i8* @strcpy(i8*, i8*) #4

; Function Attrs: nounwind readonly
declare i64 @strlen(i8*) #2

; Function Attrs: nounwind readonly
declare i32 @toupper(i32) #2

; Function Attrs: noinline nounwind optnone
define i32 @read_symbol() #0 {
entry:
  %retval = alloca i32, align 4
  %retval1 = alloca i32, align 4
  %len = alloca i32, align 4
  %call = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.26, i32 0, i32 0), i8* getelementptr inbounds ([64 x i8], [64 x i8]* @_symbol_buffer, i32 0, i32 0))
  store i32 %call, i32* %retval1, align 4
  %0 = load i32, i32* %retval1, align 4
  %cmp = icmp ne i32 %0, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  store i32 1, i32* %len, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end
  %1 = load i32, i32* %len, align 4
  %cmp2 = icmp slt i32 %1, 64
  br i1 %cmp2, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %2 = load i32, i32* %len, align 4
  %idx.ext = sext i32 %2 to i64
  %add.ptr = getelementptr inbounds i8, i8* getelementptr inbounds ([64 x i8], [64 x i8]* @_symbol_buffer, i32 0, i32 0), i64 %idx.ext
  %call3 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.16, i32 0, i32 0), i8* %add.ptr)
  store i32 %call3, i32* %retval1, align 4
  %3 = load i32, i32* %retval1, align 4
  %cmp4 = icmp ne i32 %3, 1
  br i1 %cmp4, label %if.then9, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %for.body
  %call5 = call i16** @__ctype_b_loc() #9
  %4 = load i16*, i16** %call5, align 8
  %5 = load i32, i32* %len, align 4
  %idxprom = sext i32 %5 to i64
  %arrayidx = getelementptr inbounds [64 x i8], [64 x i8]* @_symbol_buffer, i64 0, i64 %idxprom
  %6 = load i8, i8* %arrayidx, align 1
  %conv = sext i8 %6 to i32
  %idxprom6 = sext i32 %conv to i64
  %arrayidx7 = getelementptr inbounds i16, i16* %4, i64 %idxprom6
  %7 = load i16, i16* %arrayidx7, align 2
  %conv8 = zext i16 %7 to i32
  %and = and i32 %conv8, 8192
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %if.then9, label %if.end10

if.then9:                                         ; preds = %lor.lhs.false, %for.body
  br label %for.end

if.end10:                                         ; preds = %lor.lhs.false
  br label %for.inc

for.inc:                                          ; preds = %if.end10
  %8 = load i32, i32* %len, align 4
  %inc = add nsw i32 %8, 1
  store i32 %inc, i32* %len, align 4
  br label %for.cond

for.end:                                          ; preds = %if.then9, %for.cond
  %9 = load i32, i32* %len, align 4
  %cmp11 = icmp eq i32 %9, 64
  br i1 %cmp11, label %if.then13, label %if.end14

if.then13:                                        ; preds = %for.end
  store i32 0, i32* %retval, align 4
  br label %return

if.end14:                                         ; preds = %for.end
  %10 = load i32, i32* %len, align 4
  %idxprom15 = sext i32 %10 to i64
  %arrayidx16 = getelementptr inbounds [64 x i8], [64 x i8]* @_symbol_buffer, i64 0, i64 %idxprom15
  store i8 0, i8* %arrayidx16, align 1
  %call17 = call i32 @lookup_symbol(i8* getelementptr inbounds ([64 x i8], [64 x i8]* @_symbol_buffer, i32 0, i32 0))
  store i32 %call17, i32* %retval, align 4
  br label %return

return:                                           ; preds = %if.end14, %if.then13, %if.then
  %11 = load i32, i32* %retval, align 4
  ret i32 %11
}

; Function Attrs: nounwind readnone
declare i16** @__ctype_b_loc() #5

; Function Attrs: noinline nounwind optnone
define void @print_symbol(i32 %symbol_id) #0 {
entry:
  %symbol_id.addr = alloca i32, align 4
  store i32 %symbol_id, i32* %symbol_id.addr, align 4
  %0 = load i32, i32* %symbol_id.addr, align 4
  %call = call i8* @_SYM(i32 %0)
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.20, i32 0, i32 0), i8* %call)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline nounwind optnone
define void @set_io_test() #0 {
entry:
  %sets = alloca [26 x %struct.set*], align 16
  %i = alloca i32, align 4
  %cmd = alloca i32, align 4
  %idx = alloca i32, align 4
  %idx16 = alloca i32, align 4
  %i23 = alloca i32, align 4
  %idx32 = alloca i32, align 4
  %len = alloca i32, align 4
  %a = alloca i32*, align 8
  %i44 = alloca i32, align 4
  %idx63 = alloca i32, align 4
  %idx79 = alloca i32, align 4
  %i86 = alloca i32, align 4
  %idx1 = alloca i32, align 4
  %idx2 = alloca i32, align 4
  %idx134 = alloca i32, align 4
  %idx1141 = alloca i32, align 4
  %idx2148 = alloca i32, align 4
  %idx167 = alloca i32, align 4
  %idx1174 = alloca i32, align 4
  %idx2181 = alloca i32, align 4
  %idx200 = alloca i32, align 4
  %idx1207 = alloca i32, align 4
  %idx2214 = alloca i32, align 4
  %idx233 = alloca i32, align 4
  %idx249 = alloca i32, align 4
  %i278 = alloca i32, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %0, 26
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i32, i32* %i, align 4
  %idxprom = sext i32 %1 to i64
  %arrayidx = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom
  store %struct.set* null, %struct.set** %arrayidx, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %2 = load i32, i32* %i, align 4
  %inc = add nsw i32 %2, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  br label %while.body

while.body:                                       ; preds = %for.end, %if.end277
  %call = call i32 @read_symbol()
  store i32 %call, i32* %cmd, align 4
  %3 = load i32, i32* %cmd, align 4
  %cmp1 = icmp eq i32 %3, 0
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  call void @quit(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.27, i32 0, i32 0))
  br label %if.end

if.end:                                           ; preds = %if.then, %while.body
  %4 = load i32, i32* %cmd, align 4
  %call2 = call i32 @lookup_symbol(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.28, i32 0, i32 0))
  %cmp3 = icmp eq i32 %4, %call2
  br i1 %cmp3, label %if.then4, label %if.else

if.then4:                                         ; preds = %if.end
  %call5 = call i32 @read_set_index()
  store i32 %call5, i32* %idx, align 4
  %5 = load i32, i32* %idx, align 4
  %idxprom6 = sext i32 %5 to i64
  %arrayidx7 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom6
  %6 = load %struct.set*, %struct.set** %arrayidx7, align 8
  %tobool = icmp ne %struct.set* %6, null
  br i1 %tobool, label %if.then8, label %if.end9

if.then8:                                         ; preds = %if.then4
  call void @quit(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.29, i32 0, i32 0))
  br label %if.end9

if.end9:                                          ; preds = %if.then8, %if.then4
  %call10 = call %struct.set* @empty_set()
  %7 = load i32, i32* %idx, align 4
  %idxprom11 = sext i32 %7 to i64
  %arrayidx12 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom11
  store %struct.set* %call10, %struct.set** %arrayidx12, align 8
  br label %if.end277

if.else:                                          ; preds = %if.end
  %8 = load i32, i32* %cmd, align 4
  %call13 = call i32 @lookup_symbol(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.30, i32 0, i32 0))
  %cmp14 = icmp eq i32 %8, %call13
  br i1 %cmp14, label %if.then15, label %if.else28

if.then15:                                        ; preds = %if.else
  %call17 = call i32 @read_set_index()
  store i32 %call17, i32* %idx16, align 4
  %9 = load i32, i32* %idx16, align 4
  %idxprom18 = sext i32 %9 to i64
  %arrayidx19 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom18
  %10 = load %struct.set*, %struct.set** %arrayidx19, align 8
  %tobool20 = icmp ne %struct.set* %10, null
  br i1 %tobool20, label %if.then21, label %if.end22

if.then21:                                        ; preds = %if.then15
  call void @quit(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.29, i32 0, i32 0))
  br label %if.end22

if.end22:                                         ; preds = %if.then21, %if.then15
  %call24 = call i32 @read_i()
  store i32 %call24, i32* %i23, align 4
  %11 = load i32, i32* %i23, align 4
  %call25 = call %struct.set* @singleton(i32 %11)
  %12 = load i32, i32* %idx16, align 4
  %idxprom26 = sext i32 %12 to i64
  %arrayidx27 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom26
  store %struct.set* %call25, %struct.set** %arrayidx27, align 8
  br label %if.end276

if.else28:                                        ; preds = %if.else
  %13 = load i32, i32* %cmd, align 4
  %call29 = call i32 @lookup_symbol(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.31, i32 0, i32 0))
  %cmp30 = icmp eq i32 %13, %call29
  br i1 %cmp30, label %if.then31, label %if.else58

if.then31:                                        ; preds = %if.else28
  %call33 = call i32 @read_set_index()
  store i32 %call33, i32* %idx32, align 4
  %14 = load i32, i32* %idx32, align 4
  %idxprom34 = sext i32 %14 to i64
  %arrayidx35 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom34
  %15 = load %struct.set*, %struct.set** %arrayidx35, align 8
  %tobool36 = icmp ne %struct.set* %15, null
  br i1 %tobool36, label %if.then37, label %if.end38

if.then37:                                        ; preds = %if.then31
  call void @quit(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.29, i32 0, i32 0))
  br label %if.end38

if.end38:                                         ; preds = %if.then37, %if.then31
  %call39 = call i32 @read_i()
  store i32 %call39, i32* %len, align 4
  %16 = load i32, i32* %len, align 4
  %cmp40 = icmp slt i32 %16, 1
  br i1 %cmp40, label %if.then41, label %if.end42

if.then41:                                        ; preds = %if.end38
  call void @quit(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @.str.32, i32 0, i32 0))
  br label %if.end42

if.end42:                                         ; preds = %if.then41, %if.end38
  %17 = load i32, i32* %len, align 4
  %conv = sext i32 %17 to i64
  %mul = mul i64 %conv, 4
  %call43 = call noalias i8* @malloc(i64 %mul) #8
  %18 = bitcast i8* %call43 to i32*
  store i32* %18, i32** %a, align 8
  store i32 0, i32* %i44, align 4
  br label %for.cond45

for.cond45:                                       ; preds = %for.inc52, %if.end42
  %19 = load i32, i32* %i44, align 4
  %20 = load i32, i32* %len, align 4
  %cmp46 = icmp slt i32 %19, %20
  br i1 %cmp46, label %for.body48, label %for.end54

for.body48:                                       ; preds = %for.cond45
  %call49 = call i32 @read_i()
  %21 = load i32*, i32** %a, align 8
  %22 = load i32, i32* %i44, align 4
  %idxprom50 = sext i32 %22 to i64
  %arrayidx51 = getelementptr inbounds i32, i32* %21, i64 %idxprom50
  store i32 %call49, i32* %arrayidx51, align 4
  br label %for.inc52

for.inc52:                                        ; preds = %for.body48
  %23 = load i32, i32* %i44, align 4
  %inc53 = add nsw i32 %23, 1
  store i32 %inc53, i32* %i44, align 4
  br label %for.cond45

for.end54:                                        ; preds = %for.cond45
  %24 = load i32*, i32** %a, align 8
  %25 = load i32, i32* %len, align 4
  %call55 = call %struct.set* @set_from_array(i32* %24, i32 %25)
  %26 = load i32, i32* %idx32, align 4
  %idxprom56 = sext i32 %26 to i64
  %arrayidx57 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom56
  store %struct.set* %call55, %struct.set** %arrayidx57, align 8
  %27 = load i32*, i32** %a, align 8
  %28 = bitcast i32* %27 to i8*
  call void @free(i8* %28) #8
  br label %if.end275

if.else58:                                        ; preds = %if.else28
  %29 = load i32, i32* %cmd, align 4
  %call59 = call i32 @lookup_symbol(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.33, i32 0, i32 0))
  %cmp60 = icmp eq i32 %29, %call59
  br i1 %cmp60, label %if.then62, label %if.else74

if.then62:                                        ; preds = %if.else58
  %call64 = call i32 @read_set_index()
  store i32 %call64, i32* %idx63, align 4
  %30 = load i32, i32* %idx63, align 4
  %idxprom65 = sext i32 %30 to i64
  %arrayidx66 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom65
  %31 = load %struct.set*, %struct.set** %arrayidx66, align 8
  %tobool67 = icmp ne %struct.set* %31, null
  br i1 %tobool67, label %if.end69, label %if.then68

if.then68:                                        ; preds = %if.then62
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end69

if.end69:                                         ; preds = %if.then68, %if.then62
  %32 = load i32, i32* %idx63, align 4
  %add = add nsw i32 %32, 97
  %33 = load i32, i32* %idx63, align 4
  %idxprom70 = sext i32 %33 to i64
  %arrayidx71 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom70
  %34 = load %struct.set*, %struct.set** %arrayidx71, align 8
  %call72 = call i32 @cardinality(%struct.set* %34)
  %call73 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.35, i32 0, i32 0), i32 %add, i32 %call72)
  br label %if.end274

if.else74:                                        ; preds = %if.else58
  %35 = load i32, i32* %cmd, align 4
  %call75 = call i32 @lookup_symbol(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.36, i32 0, i32 0))
  %cmp76 = icmp eq i32 %35, %call75
  br i1 %cmp76, label %if.then78, label %if.else98

if.then78:                                        ; preds = %if.else74
  %call80 = call i32 @read_set_index()
  store i32 %call80, i32* %idx79, align 4
  %36 = load i32, i32* %idx79, align 4
  %idxprom81 = sext i32 %36 to i64
  %arrayidx82 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom81
  %37 = load %struct.set*, %struct.set** %arrayidx82, align 8
  %tobool83 = icmp ne %struct.set* %37, null
  br i1 %tobool83, label %if.end85, label %if.then84

if.then84:                                        ; preds = %if.then78
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end85

if.end85:                                         ; preds = %if.then84, %if.then78
  %call87 = call i32 @read_i()
  store i32 %call87, i32* %i86, align 4
  %38 = load i32, i32* %idx79, align 4
  %idxprom88 = sext i32 %38 to i64
  %arrayidx89 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom88
  %39 = load %struct.set*, %struct.set** %arrayidx89, align 8
  %40 = load i32, i32* %i86, align 4
  %call90 = call zeroext i1 @set_member(%struct.set* %39, i32 %40)
  br i1 %call90, label %if.then91, label %if.else94

if.then91:                                        ; preds = %if.end85
  %41 = load i32, i32* %i86, align 4
  %42 = load i32, i32* %idx79, align 4
  %add92 = add nsw i32 %42, 97
  %call93 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.37, i32 0, i32 0), i32 %41, i32 %add92)
  br label %if.end97

if.else94:                                        ; preds = %if.end85
  %43 = load i32, i32* %i86, align 4
  %44 = load i32, i32* %idx79, align 4
  %add95 = add nsw i32 %44, 97
  %call96 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str.38, i32 0, i32 0), i32 %43, i32 %add95)
  br label %if.end97

if.end97:                                         ; preds = %if.else94, %if.then91
  br label %if.end273

if.else98:                                        ; preds = %if.else74
  %45 = load i32, i32* %cmd, align 4
  %call99 = call i32 @lookup_symbol(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.39, i32 0, i32 0))
  %cmp100 = icmp eq i32 %45, %call99
  br i1 %cmp100, label %if.then102, label %if.else129

if.then102:                                       ; preds = %if.else98
  %call103 = call i32 @read_set_index()
  store i32 %call103, i32* %idx1, align 4
  %46 = load i32, i32* %idx1, align 4
  %idxprom104 = sext i32 %46 to i64
  %arrayidx105 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom104
  %47 = load %struct.set*, %struct.set** %arrayidx105, align 8
  %tobool106 = icmp ne %struct.set* %47, null
  br i1 %tobool106, label %if.end108, label %if.then107

if.then107:                                       ; preds = %if.then102
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end108

if.end108:                                        ; preds = %if.then107, %if.then102
  %call109 = call i32 @read_set_index()
  store i32 %call109, i32* %idx2, align 4
  %48 = load i32, i32* %idx2, align 4
  %idxprom110 = sext i32 %48 to i64
  %arrayidx111 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom110
  %49 = load %struct.set*, %struct.set** %arrayidx111, align 8
  %tobool112 = icmp ne %struct.set* %49, null
  br i1 %tobool112, label %if.end114, label %if.then113

if.then113:                                       ; preds = %if.end108
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end114

if.end114:                                        ; preds = %if.then113, %if.end108
  %50 = load i32, i32* %idx1, align 4
  %idxprom115 = sext i32 %50 to i64
  %arrayidx116 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom115
  %51 = load %struct.set*, %struct.set** %arrayidx116, align 8
  %52 = load i32, i32* %idx2, align 4
  %idxprom117 = sext i32 %52 to i64
  %arrayidx118 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom117
  %53 = load %struct.set*, %struct.set** %arrayidx118, align 8
  %call119 = call zeroext i1 @set_equal(%struct.set* %51, %struct.set* %53)
  br i1 %call119, label %if.then120, label %if.else124

if.then120:                                       ; preds = %if.end114
  %54 = load i32, i32* %idx1, align 4
  %add121 = add nsw i32 %54, 97
  %55 = load i32, i32* %idx2, align 4
  %add122 = add nsw i32 %55, 97
  %call123 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.40, i32 0, i32 0), i32 %add121, i32 %add122)
  br label %if.end128

if.else124:                                       ; preds = %if.end114
  %56 = load i32, i32* %idx1, align 4
  %add125 = add nsw i32 %56, 97
  %57 = load i32, i32* %idx2, align 4
  %add126 = add nsw i32 %57, 97
  %call127 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.41, i32 0, i32 0), i32 %add125, i32 %add126)
  br label %if.end128

if.end128:                                        ; preds = %if.else124, %if.then120
  br label %if.end272

if.else129:                                       ; preds = %if.else98
  %58 = load i32, i32* %cmd, align 4
  %call130 = call i32 @lookup_symbol(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.42, i32 0, i32 0))
  %cmp131 = icmp eq i32 %58, %call130
  br i1 %cmp131, label %if.then133, label %if.else162

if.then133:                                       ; preds = %if.else129
  %call135 = call i32 @read_set_index()
  store i32 %call135, i32* %idx134, align 4
  %59 = load i32, i32* %idx134, align 4
  %idxprom136 = sext i32 %59 to i64
  %arrayidx137 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom136
  %60 = load %struct.set*, %struct.set** %arrayidx137, align 8
  %tobool138 = icmp ne %struct.set* %60, null
  br i1 %tobool138, label %if.then139, label %if.end140

if.then139:                                       ; preds = %if.then133
  call void @quit(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.29, i32 0, i32 0))
  br label %if.end140

if.end140:                                        ; preds = %if.then139, %if.then133
  %call142 = call i32 @read_set_index()
  store i32 %call142, i32* %idx1141, align 4
  %61 = load i32, i32* %idx1141, align 4
  %idxprom143 = sext i32 %61 to i64
  %arrayidx144 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom143
  %62 = load %struct.set*, %struct.set** %arrayidx144, align 8
  %tobool145 = icmp ne %struct.set* %62, null
  br i1 %tobool145, label %if.end147, label %if.then146

if.then146:                                       ; preds = %if.end140
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end147

if.end147:                                        ; preds = %if.then146, %if.end140
  %call149 = call i32 @read_set_index()
  store i32 %call149, i32* %idx2148, align 4
  %63 = load i32, i32* %idx2148, align 4
  %idxprom150 = sext i32 %63 to i64
  %arrayidx151 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom150
  %64 = load %struct.set*, %struct.set** %arrayidx151, align 8
  %tobool152 = icmp ne %struct.set* %64, null
  br i1 %tobool152, label %if.end154, label %if.then153

if.then153:                                       ; preds = %if.end147
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end154

if.end154:                                        ; preds = %if.then153, %if.end147
  %65 = load i32, i32* %idx1141, align 4
  %idxprom155 = sext i32 %65 to i64
  %arrayidx156 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom155
  %66 = load %struct.set*, %struct.set** %arrayidx156, align 8
  %67 = load i32, i32* %idx2148, align 4
  %idxprom157 = sext i32 %67 to i64
  %arrayidx158 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom157
  %68 = load %struct.set*, %struct.set** %arrayidx158, align 8
  %call159 = call %struct.set* @set_union(%struct.set* %66, %struct.set* %68)
  %69 = load i32, i32* %idx134, align 4
  %idxprom160 = sext i32 %69 to i64
  %arrayidx161 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom160
  store %struct.set* %call159, %struct.set** %arrayidx161, align 8
  br label %if.end271

if.else162:                                       ; preds = %if.else129
  %70 = load i32, i32* %cmd, align 4
  %call163 = call i32 @lookup_symbol(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.43, i32 0, i32 0))
  %cmp164 = icmp eq i32 %70, %call163
  br i1 %cmp164, label %if.then166, label %if.else195

if.then166:                                       ; preds = %if.else162
  %call168 = call i32 @read_set_index()
  store i32 %call168, i32* %idx167, align 4
  %71 = load i32, i32* %idx167, align 4
  %idxprom169 = sext i32 %71 to i64
  %arrayidx170 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom169
  %72 = load %struct.set*, %struct.set** %arrayidx170, align 8
  %tobool171 = icmp ne %struct.set* %72, null
  br i1 %tobool171, label %if.then172, label %if.end173

if.then172:                                       ; preds = %if.then166
  call void @quit(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.29, i32 0, i32 0))
  br label %if.end173

if.end173:                                        ; preds = %if.then172, %if.then166
  %call175 = call i32 @read_set_index()
  store i32 %call175, i32* %idx1174, align 4
  %73 = load i32, i32* %idx1174, align 4
  %idxprom176 = sext i32 %73 to i64
  %arrayidx177 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom176
  %74 = load %struct.set*, %struct.set** %arrayidx177, align 8
  %tobool178 = icmp ne %struct.set* %74, null
  br i1 %tobool178, label %if.end180, label %if.then179

if.then179:                                       ; preds = %if.end173
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end180

if.end180:                                        ; preds = %if.then179, %if.end173
  %call182 = call i32 @read_set_index()
  store i32 %call182, i32* %idx2181, align 4
  %75 = load i32, i32* %idx2181, align 4
  %idxprom183 = sext i32 %75 to i64
  %arrayidx184 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom183
  %76 = load %struct.set*, %struct.set** %arrayidx184, align 8
  %tobool185 = icmp ne %struct.set* %76, null
  br i1 %tobool185, label %if.end187, label %if.then186

if.then186:                                       ; preds = %if.end180
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end187

if.end187:                                        ; preds = %if.then186, %if.end180
  %77 = load i32, i32* %idx1174, align 4
  %idxprom188 = sext i32 %77 to i64
  %arrayidx189 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom188
  %78 = load %struct.set*, %struct.set** %arrayidx189, align 8
  %79 = load i32, i32* %idx2181, align 4
  %idxprom190 = sext i32 %79 to i64
  %arrayidx191 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom190
  %80 = load %struct.set*, %struct.set** %arrayidx191, align 8
  %call192 = call %struct.set* @set_intersect(%struct.set* %78, %struct.set* %80)
  %81 = load i32, i32* %idx167, align 4
  %idxprom193 = sext i32 %81 to i64
  %arrayidx194 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom193
  store %struct.set* %call192, %struct.set** %arrayidx194, align 8
  br label %if.end270

if.else195:                                       ; preds = %if.else162
  %82 = load i32, i32* %cmd, align 4
  %call196 = call i32 @lookup_symbol(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.44, i32 0, i32 0))
  %cmp197 = icmp eq i32 %82, %call196
  br i1 %cmp197, label %if.then199, label %if.else228

if.then199:                                       ; preds = %if.else195
  %call201 = call i32 @read_set_index()
  store i32 %call201, i32* %idx200, align 4
  %83 = load i32, i32* %idx200, align 4
  %idxprom202 = sext i32 %83 to i64
  %arrayidx203 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom202
  %84 = load %struct.set*, %struct.set** %arrayidx203, align 8
  %tobool204 = icmp ne %struct.set* %84, null
  br i1 %tobool204, label %if.then205, label %if.end206

if.then205:                                       ; preds = %if.then199
  call void @quit(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.29, i32 0, i32 0))
  br label %if.end206

if.end206:                                        ; preds = %if.then205, %if.then199
  %call208 = call i32 @read_set_index()
  store i32 %call208, i32* %idx1207, align 4
  %85 = load i32, i32* %idx1207, align 4
  %idxprom209 = sext i32 %85 to i64
  %arrayidx210 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom209
  %86 = load %struct.set*, %struct.set** %arrayidx210, align 8
  %tobool211 = icmp ne %struct.set* %86, null
  br i1 %tobool211, label %if.end213, label %if.then212

if.then212:                                       ; preds = %if.end206
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end213

if.end213:                                        ; preds = %if.then212, %if.end206
  %call215 = call i32 @read_set_index()
  store i32 %call215, i32* %idx2214, align 4
  %87 = load i32, i32* %idx2214, align 4
  %idxprom216 = sext i32 %87 to i64
  %arrayidx217 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom216
  %88 = load %struct.set*, %struct.set** %arrayidx217, align 8
  %tobool218 = icmp ne %struct.set* %88, null
  br i1 %tobool218, label %if.end220, label %if.then219

if.then219:                                       ; preds = %if.end213
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end220

if.end220:                                        ; preds = %if.then219, %if.end213
  %89 = load i32, i32* %idx1207, align 4
  %idxprom221 = sext i32 %89 to i64
  %arrayidx222 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom221
  %90 = load %struct.set*, %struct.set** %arrayidx222, align 8
  %91 = load i32, i32* %idx2214, align 4
  %idxprom223 = sext i32 %91 to i64
  %arrayidx224 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom223
  %92 = load %struct.set*, %struct.set** %arrayidx224, align 8
  %call225 = call %struct.set* @set_diff(%struct.set* %90, %struct.set* %92)
  %93 = load i32, i32* %idx200, align 4
  %idxprom226 = sext i32 %93 to i64
  %arrayidx227 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom226
  store %struct.set* %call225, %struct.set** %arrayidx227, align 8
  br label %if.end269

if.else228:                                       ; preds = %if.else195
  %94 = load i32, i32* %cmd, align 4
  %call229 = call i32 @lookup_symbol(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.45, i32 0, i32 0))
  %cmp230 = icmp eq i32 %94, %call229
  br i1 %cmp230, label %if.then232, label %if.else244

if.then232:                                       ; preds = %if.else228
  %call234 = call i32 @read_set_index()
  store i32 %call234, i32* %idx233, align 4
  %95 = load i32, i32* %idx233, align 4
  %idxprom235 = sext i32 %95 to i64
  %arrayidx236 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom235
  %96 = load %struct.set*, %struct.set** %arrayidx236, align 8
  %tobool237 = icmp ne %struct.set* %96, null
  br i1 %tobool237, label %if.end239, label %if.then238

if.then238:                                       ; preds = %if.then232
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end239

if.end239:                                        ; preds = %if.then238, %if.then232
  %97 = load i32, i32* %idx233, align 4
  %add240 = add nsw i32 %97, 97
  %call241 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.46, i32 0, i32 0), i32 %add240)
  %98 = load i32, i32* %idx233, align 4
  %idxprom242 = sext i32 %98 to i64
  %arrayidx243 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom242
  %99 = load %struct.set*, %struct.set** %arrayidx243, align 8
  call void @set_print(%struct.set* %99)
  br label %if.end268

if.else244:                                       ; preds = %if.else228
  %100 = load i32, i32* %cmd, align 4
  %call245 = call i32 @lookup_symbol(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.47, i32 0, i32 0))
  %cmp246 = icmp eq i32 %100, %call245
  br i1 %cmp246, label %if.then248, label %if.else260

if.then248:                                       ; preds = %if.else244
  %call250 = call i32 @read_set_index()
  store i32 %call250, i32* %idx249, align 4
  %101 = load i32, i32* %idx249, align 4
  %idxprom251 = sext i32 %101 to i64
  %arrayidx252 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom251
  %102 = load %struct.set*, %struct.set** %arrayidx252, align 8
  %tobool253 = icmp ne %struct.set* %102, null
  br i1 %tobool253, label %if.end255, label %if.then254

if.then254:                                       ; preds = %if.then248
  call void @quit(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.34, i32 0, i32 0))
  br label %if.end255

if.end255:                                        ; preds = %if.then254, %if.then248
  %103 = load i32, i32* %idx249, align 4
  %idxprom256 = sext i32 %103 to i64
  %arrayidx257 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom256
  %104 = load %struct.set*, %struct.set** %arrayidx257, align 8
  call void @set_destroy(%struct.set* %104)
  %105 = load i32, i32* %idx249, align 4
  %idxprom258 = sext i32 %105 to i64
  %arrayidx259 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom258
  store %struct.set* null, %struct.set** %arrayidx259, align 8
  br label %if.end267

if.else260:                                       ; preds = %if.else244
  %106 = load i32, i32* %cmd, align 4
  %call261 = call i32 @lookup_symbol(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.48, i32 0, i32 0))
  %cmp262 = icmp eq i32 %106, %call261
  br i1 %cmp262, label %if.then264, label %if.else265

if.then264:                                       ; preds = %if.else260
  br label %while.end

if.else265:                                       ; preds = %if.else260
  call void @quit(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.49, i32 0, i32 0))
  br label %if.end266

if.end266:                                        ; preds = %if.else265
  br label %if.end267

if.end267:                                        ; preds = %if.end266, %if.end255
  br label %if.end268

if.end268:                                        ; preds = %if.end267, %if.end239
  br label %if.end269

if.end269:                                        ; preds = %if.end268, %if.end220
  br label %if.end270

if.end270:                                        ; preds = %if.end269, %if.end187
  br label %if.end271

if.end271:                                        ; preds = %if.end270, %if.end154
  br label %if.end272

if.end272:                                        ; preds = %if.end271, %if.end128
  br label %if.end273

if.end273:                                        ; preds = %if.end272, %if.end97
  br label %if.end274

if.end274:                                        ; preds = %if.end273, %if.end69
  br label %if.end275

if.end275:                                        ; preds = %if.end274, %for.end54
  br label %if.end276

if.end276:                                        ; preds = %if.end275, %if.end22
  br label %if.end277

if.end277:                                        ; preds = %if.end276, %if.end9
  br label %while.body

while.end:                                        ; preds = %if.then264
  store i32 0, i32* %i278, align 4
  br label %for.cond279

for.cond279:                                      ; preds = %for.inc290, %while.end
  %107 = load i32, i32* %i278, align 4
  %cmp280 = icmp slt i32 %107, 26
  br i1 %cmp280, label %for.body282, label %for.end292

for.body282:                                      ; preds = %for.cond279
  %108 = load i32, i32* %i278, align 4
  %idxprom283 = sext i32 %108 to i64
  %arrayidx284 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom283
  %109 = load %struct.set*, %struct.set** %arrayidx284, align 8
  %tobool285 = icmp ne %struct.set* %109, null
  br i1 %tobool285, label %if.then286, label %if.end289

if.then286:                                       ; preds = %for.body282
  %110 = load i32, i32* %i278, align 4
  %idxprom287 = sext i32 %110 to i64
  %arrayidx288 = getelementptr inbounds [26 x %struct.set*], [26 x %struct.set*]* %sets, i64 0, i64 %idxprom287
  %111 = load %struct.set*, %struct.set** %arrayidx288, align 8
  call void @set_destroy(%struct.set* %111)
  br label %if.end289

if.end289:                                        ; preds = %if.then286, %for.body282
  br label %for.inc290

for.inc290:                                       ; preds = %if.end289
  %112 = load i32, i32* %i278, align 4
  %inc291 = add nsw i32 %112, 1
  store i32 %inc291, i32* %i278, align 4
  br label %for.cond279

for.end292:                                       ; preds = %for.cond279
  ret void
}

; Function Attrs: noinline nounwind optnone
define internal void @quit(i8* %msg) #0 {
entry:
  %msg.addr = alloca i8*, align 8
  store i8* %msg, i8** %msg.addr, align 8
  %0 = load i8*, i8** %msg.addr, align 8
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.51, i32 0, i32 0), i8* %0)
  call void @exit(i32 1) #7
  unreachable

return:                                           ; No predecessors!
  ret void
}

; Function Attrs: noinline nounwind optnone
define internal i32 @read_set_index() #0 {
entry:
  %c = alloca i8, align 1
  %index = alloca i32, align 4
  store i8 0, i8* %c, align 1
  %call = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.26, i32 0, i32 0), i8* %c)
  %cmp = icmp ne i32 %call, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  call void @quit(i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.52, i32 0, i32 0))
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %0 = load i8, i8* %c, align 1
  %conv = sext i8 %0 to i32
  %sub = sub nsw i32 %conv, 97
  store i32 %sub, i32* %index, align 4
  %1 = load i32, i32* %index, align 4
  %cmp1 = icmp slt i32 %1, 0
  br i1 %cmp1, label %if.then5, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %if.end
  %2 = load i32, i32* %index, align 4
  %cmp3 = icmp sge i32 %2, 26
  br i1 %cmp3, label %if.then5, label %if.end6

if.then5:                                         ; preds = %lor.lhs.false, %if.end
  call void @quit(i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.52, i32 0, i32 0))
  br label %if.end6

if.end6:                                          ; preds = %if.then5, %lor.lhs.false
  %3 = load i32, i32* %index, align 4
  ret i32 %3
}

declare %struct.set* @empty_set() #1

; Function Attrs: noinline nounwind optnone
define internal i32 @read_i() #0 {
entry:
  %i = alloca i32, align 4
  %call = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.14, i32 0, i32 0), i32* %i)
  %cmp = icmp ne i32 %call, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  call void @quit(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.53, i32 0, i32 0))
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %0 = load i32, i32* %i, align 4
  ret i32 %0
}

declare %struct.set* @singleton(i32) #1

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #4

declare %struct.set* @set_from_array(i32*, i32) #1

; Function Attrs: nounwind
declare void @free(i8*) #4

declare i32 @cardinality(%struct.set*) #1

declare zeroext i1 @set_member(%struct.set*, i32) #1

declare zeroext i1 @set_equal(%struct.set*, %struct.set*) #1

declare %struct.set* @set_union(%struct.set*, %struct.set*) #1

declare %struct.set* @set_intersect(%struct.set*, %struct.set*) #1

declare %struct.set* @set_diff(%struct.set*, %struct.set*) #1

declare void @set_print(%struct.set*) #1

declare void @set_destroy(%struct.set*) #1

; Function Attrs: noreturn nounwind
declare void @exit(i32) #3

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readonly "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind readnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { nounwind readonly }
attributes #7 = { noreturn nounwind }
attributes #8 = { nounwind }
attributes #9 = { nounwind readnone }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 7.1.0 (https://github.com/llvm-mirror/clang.git 4519e2637fcc4bf6e3049a0a80e6a5e7b97667cb) (https://github.com/llvm-mirror/llvm.git dd3329aeb25d87d4ac6429c0af220f92e1ba5f26)"}
!1 = !{i32 1, !"wchar_size", i32 4}
