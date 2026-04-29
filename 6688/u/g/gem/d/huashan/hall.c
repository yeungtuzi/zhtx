//hall.c
#include <ansi.h>
inherit ROOM;
void dest_npc();
void create()
{
    set("short","梅庄大厅");
    set("long",@LONG
大厅的正中间挂着一副颇具功力的泼墨画，画中所绘是一个仙人的背面，
墨意淋漓，笔力雄健，又见画上题款是：“丹青生大醉后泼墨”八字，笔法
森严，一笔笔便如长剑的刺划。显而易见，画画的人不仅是丹青妙手，也是
一位武学修为不凡的高手
LONG);
     set("exits",([
         "north" :__DIR__"yuedong",
         "south" :__DIR__"gate",
     ]));
     set("happened",0);
     setup();
//     replace_program(ROOM);
}
int valid_leave(object ob,string dir)
{
        object ppl;
        if(dir=="south")
        {
           if(ob->query("win_huangzhong"))
           {
           remove_call_out("dest_npc");
           call_out("dest_npc",1);
           if(!query("happened"))         
           {
           ppl=new(__DIR__"npc/danqingsheng");
           ppl->move(environment(ob));
           set("happened",1);
           message_vision(HIY"你只听得背后一声大叫：＂清留步＂.\n"NOR,ob);
           message_vision(HIY"你回头一看，原来是丹青生满头大汗地追来了．\n"NOR,ob);
           message_vision(HIY"你不由停下了脚步．\n"NOR,ob);
           }
           return notify_fail("你想离开，但是发觉有些事情还没有做．\n");           	
           }
        }
        return 1;
}
void dest_npc()
{       object room1;
        object *inv;
        int j;
        string name;
        room1=load_object(__DIR__"jiushi");
        inv=all_inventory(room1);
        for(j=0;j<sizeof(inv);j++)
        { name=inv[j]->query("id");
         if(name=="danqing sheng")
         destruct(inv[j]);
        }
}               
