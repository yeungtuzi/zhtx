//9jiechuan.c 九节朽木椽
//by emote

inherit ROOM;

void create()
{
	set("short","九节朽木椽");
	set("long",
@LONG
从朝元洞口沿栈道直下，西折乃为“九节朽木椽”，长六七丈，宽不足一
尺，是用九节木椽搭成的。因山高气爽，气候多变，即使换上去不久的椽也会
像朽木一样，故称“朽木椽”。此处望之森森，登之危危。过朽木椽，有一石
庄，高三四尺，粗尺许，名“定心桩”。过桩便是一石洞，就是“贺祖洞”了。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"enter": __DIR__"hezu",
		"east" : __DIR__"zhandao2",
		]));
	set("outdoors","huashan"); 
	setup();
}
