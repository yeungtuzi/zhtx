// Room: /d/tangmen/didao3.c         
//writen by tang

inherit ROOM;

void close_men();

void create()
{
        set("short", "秘室");
        set("long", @LONG
    这里放着一张石桌和一张石床，在石床上有一个老妇人正在闭目
静坐，老妇人全身散发出一种奇怪的香味，闻久了你会有头晕目眩的
感觉，老妇人的身旁站着两个五代唐门弟子。
LONG
        		);
        set("exits", ([ /* sizeof() == 1*/
  		"south"   : __DIR__"cangjiange",  
		]));   
        set("objects",([
                CLASS_D("tangmen")+"/madam"  : 1,
		__DIR__"npc/dizi2"	: 2,
                ]));

        setup();
	replace_program(ROOM);
}

void init()
{

}

