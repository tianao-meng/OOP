; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.sequence = type opaque

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@_failure = internal global i32 0, align 4
@.str.1 = private unnamed_addr constant [4 x i8] c" %c\00", align 1
@.str.2 = private unnamed_addr constant [12 x i8] c"length: %d\0A\00", align 1
@.str.3 = private unnamed_addr constant [17 x i8] c"item_at(%d): %d\0A\00", align 1
@.str.4 = private unnamed_addr constant [29 x i8] c"exit: invalid command (%c).\0A\00", align 1

; Function Attrs: noinline nounwind optnone
define i32 @get_int() #0 {
entry:
  %i = alloca i32, align 4
  %call = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* %i)
  %cmp = icmp ne i32 %call, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 1, i32* @_failure, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %0 = load i32, i32* %i, align 4
  ret i32 %0
}

declare i32 @__isoc99_scanf(i8*, ...) #1

; Function Attrs: noinline nounwind optnone
define void @test_sequence() #0 {
entry:
  %seq = alloca %struct.sequence*, align 8
  %cmd = alloca i8, align 1
  %at = alloca i32, align 4
  %at26 = alloca i32, align 4
  %val = alloca i32, align 4
  %at37 = alloca i32, align 4
  %call = call %struct.sequence* @sequence_create()
  store %struct.sequence* %call, %struct.sequence** %seq, align 8
  br label %while.body

while.body:                                       ; preds = %entry, %if.end55
  %call1 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i8* %cmd)
  %cmp = icmp ne i32 %call1, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  br label %while.end

if.end:                                           ; preds = %while.body
  %0 = load i8, i8* %cmd, align 1
  %conv = sext i8 %0 to i32
  %cmp2 = icmp eq i32 %conv, 113
  br i1 %cmp2, label %if.then4, label %if.end5

if.then4:                                         ; preds = %if.end
  br label %while.end

if.end5:                                          ; preds = %if.end
  %1 = load i8, i8* %cmd, align 1
  %conv6 = sext i8 %1 to i32
  %cmp7 = icmp eq i32 %conv6, 108
  br i1 %cmp7, label %if.then9, label %if.else

if.then9:                                         ; preds = %if.end5
  %2 = load %struct.sequence*, %struct.sequence** %seq, align 8
  %call10 = call i32 @sequence_length(%struct.sequence* %2)
  %call11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.2, i32 0, i32 0), i32 %call10)
  br label %if.end55

if.else:                                          ; preds = %if.end5
  %3 = load i8, i8* %cmd, align 1
  %conv12 = sext i8 %3 to i32
  %cmp13 = icmp eq i32 %conv12, 97
  br i1 %cmp13, label %if.then15, label %if.else21

if.then15:                                        ; preds = %if.else
  %call16 = call i32 @get_int()
  store i32 %call16, i32* %at, align 4
  %4 = load i32, i32* @_failure, align 4
  %tobool = icmp ne i32 %4, 0
  br i1 %tobool, label %if.then17, label %if.end18

if.then17:                                        ; preds = %if.then15
  br label %while.end

if.end18:                                         ; preds = %if.then15
  %5 = load i32, i32* %at, align 4
  %6 = load %struct.sequence*, %struct.sequence** %seq, align 8
  %7 = load i32, i32* %at, align 4
  %call19 = call i32 @sequence_item_at(%struct.sequence* %6, i32 %7)
  %call20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @.str.3, i32 0, i32 0), i32 %5, i32 %call19)
  br label %if.end54

if.else21:                                        ; preds = %if.else
  %8 = load i8, i8* %cmd, align 1
  %conv22 = sext i8 %8 to i32
  %cmp23 = icmp eq i32 %conv22, 105
  br i1 %cmp23, label %if.then25, label %if.else32

if.then25:                                        ; preds = %if.else21
  %call27 = call i32 @get_int()
  store i32 %call27, i32* %at26, align 4
  %call28 = call i32 @get_int()
  store i32 %call28, i32* %val, align 4
  %9 = load i32, i32* @_failure, align 4
  %tobool29 = icmp ne i32 %9, 0
  br i1 %tobool29, label %if.then30, label %if.end31

if.then30:                                        ; preds = %if.then25
  br label %while.end

if.end31:                                         ; preds = %if.then25
  %10 = load %struct.sequence*, %struct.sequence** %seq, align 8
  %11 = load i32, i32* %at26, align 4
  %12 = load i32, i32* %val, align 4
  call void @sequence_insert_at(%struct.sequence* %10, i32 %11, i32 %12)
  br label %if.end53

if.else32:                                        ; preds = %if.else21
  %13 = load i8, i8* %cmd, align 1
  %conv33 = sext i8 %13 to i32
  %cmp34 = icmp eq i32 %conv33, 114
  br i1 %cmp34, label %if.then36, label %if.else43

if.then36:                                        ; preds = %if.else32
  %call38 = call i32 @get_int()
  store i32 %call38, i32* %at37, align 4
  %14 = load i32, i32* @_failure, align 4
  %tobool39 = icmp ne i32 %14, 0
  br i1 %tobool39, label %if.then40, label %if.end41

if.then40:                                        ; preds = %if.then36
  br label %while.end

if.end41:                                         ; preds = %if.then36
  %15 = load %struct.sequence*, %struct.sequence** %seq, align 8
  %16 = load i32, i32* %at37, align 4
  %call42 = call i32 @sequence_remove_at(%struct.sequence* %15, i32 %16)
  br label %if.end52

if.else43:                                        ; preds = %if.else32
  %17 = load i8, i8* %cmd, align 1
  %conv44 = sext i8 %17 to i32
  %cmp45 = icmp eq i32 %conv44, 112
  br i1 %cmp45, label %if.then47, label %if.else48

if.then47:                                        ; preds = %if.else43
  %18 = load %struct.sequence*, %struct.sequence** %seq, align 8
  call void @sequence_print(%struct.sequence* %18)
  br label %if.end51

if.else48:                                        ; preds = %if.else43
  %19 = load i8, i8* %cmd, align 1
  %conv49 = sext i8 %19 to i32
  %call50 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.4, i32 0, i32 0), i32 %conv49)
  br label %while.end

if.end51:                                         ; preds = %if.then47
  br label %if.end52

if.end52:                                         ; preds = %if.end51, %if.end41
  br label %if.end53

if.end53:                                         ; preds = %if.end52, %if.end31
  br label %if.end54

if.end54:                                         ; preds = %if.end53, %if.end18
  br label %if.end55

if.end55:                                         ; preds = %if.end54, %if.then9
  br label %while.body

while.end:                                        ; preds = %if.else48, %if.then40, %if.then30, %if.then17, %if.then4, %if.then
  %20 = load %struct.sequence*, %struct.sequence** %seq, align 8
  call void @sequence_destroy(%struct.sequence* %20)
  %21 = load i32, i32* @_failure, align 4
  %tobool56 = icmp ne i32 %21, 0
  br i1 %tobool56, label %if.then57, label %if.end58

if.then57:                                        ; preds = %while.end
  call void @exit(i32 1) #3
  unreachable

if.end58:                                         ; preds = %while.end
  ret void
}

declare %struct.sequence* @sequence_create() #1

declare i32 @sequence_length(%struct.sequence*) #1

declare i32 @printf(i8*, ...) #1

declare i32 @sequence_item_at(%struct.sequence*, i32) #1

declare void @sequence_insert_at(%struct.sequence*, i32, i32) #1

declare i32 @sequence_remove_at(%struct.sequence*, i32) #1

declare void @sequence_print(%struct.sequence*) #1

declare void @sequence_destroy(%struct.sequence*) #1

; Function Attrs: noreturn nounwind
declare void @exit(i32) #2

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 7.1.0 (https://github.com/llvm-mirror/clang.git 4519e2637fcc4bf6e3049a0a80e6a5e7b97667cb) (https://github.com/llvm-mirror/llvm.git dd3329aeb25d87d4ac6429c0af220f92e1ba5f26)"}
!1 = !{i32 1, !"wchar_size", i32 4}
