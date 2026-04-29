#include <ansi.h>
inherit "/std/room/doom.c";

void create()
{
      set("short", HIW"村庄"NOR);
      set("long",RED"这是一个被日本鬼子扫荡后的村庄，横尸遍野，大火过后的断壁残垣冒着缕缕的黑烟，
你隐约还能听到一个孩子的哭泣，男人们全被杀死了，没有一个头颅在自己的脖子上，女人
们下体全都裸露着，上至八旬的老妪，下至扎着小辫的孩子，没有一个幸免，你看到这副惨
景不由得义愤填膺，如此丧尽天良的禽兽，天理难容啊！！而此时一个小鬼子还没离去，正
在那里上窜下跳的翻着什么，一看到你，“啊呀呀”叫了一声就扑了上来！\n"NOR);     
        set("exits", ([ 
  "north" : "/d/road/guangzhou",
]));
        set("objects", ([
        "/u/m/masterall/npc/wokou" : 1,
                        ]) );

        setup();
}

