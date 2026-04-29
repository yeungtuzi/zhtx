//gongmen.c

#include <ansi.h>
inherit ROOM;


void create()
{
 set("short",RED"宫门"NOR);
 set("long",@LONG
这是全真派重阳宫的宫门,这里整个由大块的青石铺成，极为平坦。
但因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来.
门前站着一位知客道长,北边遥遥可以望见一个高大的宫殿.
LONG
    );
  set("exits",([
    "nouth" : __DIR__"sanqingdian",
    "southdown": __DIR__"shijie1",
   ]));
  set("objects",([
    __DIR__"npc/zhike" : 1,
   ]));
  setup();
 replace_program(ROOM);
 }
   

