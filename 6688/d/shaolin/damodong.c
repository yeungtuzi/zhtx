// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19
// write by: hacker
#include <room.h>
#include <ansi.h> 

inherit ROOM;
int do_break(string); 


void create()
{
	set("short", "达摩洞");
	set("long", @LONG
这里是达摩古洞。五百年前南天竺僧人菩提达摩来到少林寺，见
此风水宝地，就住下来广罗弟子，传授禅宗，开创少林寺佛教禅宗千
年不败之基。达摩祖师常在此面壁悟道，一坐十年，壁间隐隐似仍可
看到他面壁时的打坐姿态。除地上的几块竹片外，洞中空无一物。
LONG
	);

	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));

	set("objects",([
		"d/shaolin/obj/book-bamboo" : 1,
	]));
      set("item_desc", ([
       "wall" : "这是一堵黑黝黝的石壁。\n",
       "石壁" : "这是一堵黑黝黝的石壁。\n",
    ]) );
	setup();
}

void init()
{
	object me;
      me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) 
	&&   (int) me->query("gin") >= 40 )
	{
		me->receive_damage("gin", 40);
		me->improve_skill("dodge", me->query("int"));
	}

        this_player()->set_temp("mianbi_times", 30);
        add_action("do_mianbi","面壁");	
        add_action("do_mianbi","mianbi");	
        add_action("do_break", "break"); 
}

int do_mianbi()
{
	object me;
     me = this_player();
      if ( me->query_temp("mianbi_times") ==0)
       {
        message_vision("$N面壁耗神太多，晕了过去。\n",me);
        me->set_temp("mianbi_times",random(30));
        me->unconcious();
        return 1;
       }
      
        me->add_temp("mianbi_times", -1);

	message_vision("$N面对着达摩洞後半边的石壁跌坐静思，良久，似有所悟。\n", me);
	
        if ( random(100) == 37 || random(100)==36||random(100)==35) 
        {
                tell_object(me, "突然你对达摩老祖面壁九年而大彻大悟有了领悟！\n");
                tell_object(me, "你有了一种想要打破(break)石壁的冲动。\n ");
               this_player()->set_temp("marks/面1", 1);
        return 1;
        }
	return 1;

}


 int do_break(string arg)
{   object me=this_player() ;
    int n;
    n = this_player()->query("force");
   if (me->query_temp("marks/面1") ) 
   {      
    if( !arg || arg!="石壁" ) {
        write("不要随便打碎别人的东西！\n");
        return 1;
    }
    message_vision(
    "$N深吸一口气，双掌同时拍出。\n", this_player());
        
    if (n>=200) {
        message_vision(
        "$N只听一声轰响，$N把石壁震塌了！\n", this_player());
        set("exits/enter", "/d/shaolin/dmlzhroom");
        this_player()->set("force",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
         }
    else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
       this_player()->set("force",0);
    }
    return 1;
   }
  else 
   {
     write (" 你想干嘛？\n");
   return 1;
   }
}

void close(object room)
{
    message("vision","石块稀里哗拉坍塌下来，石壁又恢复了原状。\n", room);
    room->delete("exits/enter");
}      

int valid_leave(object me, string dir)
{
        if(me->query_temp("mianbi_times") >= 0 )
             {  me->delete_temp("mianbi_times");
                me->delete_temp("mark1/面1");    } 
        return ::valid_leave();
}

