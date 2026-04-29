//chufang.c
//written by tang

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY"饭厅"NOR);
                set("long", @LONG
       这里是侠客岛吃饭的地方，收拾的相当整洁，旁边有一小灶，
正在做各种好吃的，有一个仆人正在上菜。
LONG
                );                                    
        set("no_fight",1);
        set("no_magic",1);
//        set("can_search", 1);

                set("exits", ([
                        "west"  :__DIR__"guan",
                        ]));                                          
        set("objects",([
                "/d/xkd/npc/puren2"      : 1,
                        ]));
 
                setup();
}


void init()
{
        add_action("do_chifan", "chifan");
        add_action("do_search", "search");

}

void reset() 
{
        ::reset();
        set("can_search",1);
}



int do_chifan()
{
                this_player()->start_busy(1);
                write(YEL "你坐下来饱饱地大吃了一顿\n" NOR);
                write(YEL "直吃得肚肥肠满才心满意足地站起身来\n" NOR);
                if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
                   return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

                if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝的太多了，再也塞不下任何东西了。\n");
                this_player()->set("food",this_player()->max_food_capacity());
                this_player()->set("water",this_player()->max_water_capacity());
                return 1;
}


int do_search()
{
       object me,ob;
       int luck;
       me=this_player();
       luck = random( me->query("kar") );

       if ( !query("can_search") )
                  return notify_fail("这里已经被人翻了个乱七八糟了。\n"); 

       if ( !me->query("got_ling") )
                  return notify_fail("你怎么窜到岛上来的，还要不要命了！？\n");



       message_vision("\n$N漫无目的地找了起来，一时间锅碗瓢盆被$N翻得乱七八糟！\n",me);
       delete("can_search");

         if( luck > 48 ){ 
                     tell_object(me,HIW"你突然在一堆杂物中发现一枚晶莹剔透的东西，兴高采烈的拾了起来。\n"NOR);
                     ob = new("/d/shaolin/obj/dh-dan.c");
                     ob->move(me);
                     ob->set("onwer", me);
         }else if( luck > 40 && luck <= 48 ){
                     tell_object(me,HIC"你搜了半天，什么都没找到，气得一屁股坐到地上，却好像被什么东西顶了一下。\n"NOR);
                     ob = new("/d/qiankun/obj/nineflower.c");
                     ob->move(me);
                     ob = new("/d/qiankun/obj/nineflower.c");
                     ob->move(me);
                     ob = new("/d/qiankun/obj/nineflower.c");
                     ob->move(me);
                     ob = new("/d/qiankun/obj/nineflower.c");
                     ob->move(me);
         }else if( luck > 30 && luck <= 40){
                     tell_object(me,HIW"你一不小心打碎了一个破瓦罐，里面居然有一个小药瓶。\n"NOR);
                     ob = new("/d/qiankun/obj/xiandan.c");
                     ob->move(me);
                     ob->set("owner", me);
         }else if( luck > 20 && luck <= 30){
                     tell_object(me,HIG"也不知道哪里突然蹦出只大虫子，你“吗呀”一声闪到一边去了。\n"NOR);
                     ob = new("/d/qiankun/obj/jincanwang.c");
                     ob->set("owner", me);
                     ob->move(me);
         }else if( luck > 15 && luck <= 20){
                     tell_object(me,HIC"你眼看四下无人，伸手在碗柜里掏啊掏的，也不知摸出个什么来。\n"NOR);
                     ob = new("/d/moyu/obj/nineflower.c");
                     ob->move(me);
         }else {
                     tell_object(me,"你折腾了半天，什么都没找到，结果还累得半死。\n");
         }

       return 1;
}


