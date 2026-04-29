
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIY"光明顶大殿"NOR);
	set("long", @LONG	
	拾级而上，你来到了一座极为宏伟的大殿的中央，上面高挂一
幅匾额：                


[33m		光           明           顶			[2;37;0m


	殿宽只有十丈，却长达数百丈。在这样的大殿面前，任何人都
会感觉到自身的渺小，感觉到超自然的伟力，顿生膜拜之感。大殿正中
央供奉着摩尼教圣火，明教的护教法王在此守护，不过...似乎少了一
位法王。大殿的尽头是教主理事所在。
LONG
	);

	set("valid_startroom",1);
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"yanwuchang",
	]));

       set("objects",([
		"/class/mingjiao/xiexun":1,
        	"/class/mingjiao/yintianzheng":1,
	      	"/class/mingjiao/weiyixiao":1,
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}