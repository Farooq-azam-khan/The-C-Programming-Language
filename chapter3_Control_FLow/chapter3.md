# Control Flow
- control-flow statements specify order in which computations are performed.
## 1 Statements and Blocks
- in C `;` is a statement terminatior
 - `{}` are use to grpu declarations and statements together in to a _compound statement_ or _block_.

## 2 If-Else
- If-else block ise used to expression decision,
syntax:
``` C
if (expression)
     statement_1
else
    statement_2
```
- if expression is true then the statement_1 will be executed otherwise statement_2 will be executed.
- false is defined as `0` and true is defined as `1` so
`if (expression != 0)` is same as `if(expression)`

## 3 Else-If
- when the `if` condition is not executed then the `else if` condition is check. If true then executed.

## 4 Switch
- another way of writing an if condition and in some cases is better.

## 5/6/7 Loops -- While, For, Do-While, Break, Continue
- have encountered before
- __break__ gets out of the loop,
- __continue__ re-runs the condition of the next iteration. Used for fast code and early termination. Used in conjunction with if-else if-else statements.

## 8 Goto and Labels
- C provides infinitely-abusable `goto` statements
- `goto` is almost always easy to write code withough and is never necessary
- what if you want to break out of two loops at once?
``` C
for(...;...;...)
{
  for(...;...;...)
  {
    if (siaster)
    {
      goto error;
    }
  }
}
error:
  {
    clean up mess
  }
```
