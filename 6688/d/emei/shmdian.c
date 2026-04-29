// Room: /u/cuer/emei/shmdian.c  
//cuer

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "山门殿");
	set("long", @LONG
这里是峨嵋派的山门殿，高耸如云的大殿坐落在山峰
之间，蜿蜒的石阶延伸到大殿前，再穿过大殿向山上延伸，
大殿内的过道两边是一尊尊威严的罗汉雕像。大殿内有两
名道尼在看守大殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanmen",
  "northup" : __DIR__"shijie2",
]));
	set("no_clean_up", 0); 
	set("valid_startroom", 1);
        set("objects",([
             __DIR__"npc/wenxin" : 1,
             __DIR__"npc/wenyue" : 1,  
//             __DIR__"npc/xiaofan2" : 1,
             ]));
	setup();
}
                                     

int valid_leave(object me, string dir)
{
        if( dir == "south" && (string)me->query("id") == "xunshan dizi")
                return notify_fail("不能下山!\n");
        else if (objectp(present("wenxin shitai", environment(me)))
                  ||objectp(present("wenyue shitai", environment(me)))) 
              {if( dir == "northup" ) {
                if(me->query_temp("invited_by_emei")) {
                        write("师太说: 这位施主请！\n");
                            me->delete_temp("invited_by_emei");
                }
		else if( (string)me->query("family/family_name") != "峨嵋派")
                return notify_fail(RED"师太拦住了你的去路！！\n"NOR);              
		}
              else if(dir == "south" && (int)me->query("xiashan") == 1 )
                return notify_fail(GRN"没有经过掌门的同意，不能下山！\n"NOR);  
             }
        return ::valid_leave(me, dir);
}
