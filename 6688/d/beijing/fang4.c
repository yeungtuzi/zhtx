// Room: /u/p/pock/bj/fang4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"太后寝居"NOR);
	set("long", @LONG
这里是太后的寝宫。整个房子非常的大，由一张串珠垂帘把房子分成两个部
分。外间摆着一套红木精雕的茶几椅子，茶几上摆放着一套很好的景德镇陶瓷茶
具，茶几上还有两个景泰蓝花瓶，但瓶中并没有插花。透过垂帘，里间靠北的地
方摆放着一张龙床，床的西边靠墙的地方，则是一个大衣柜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"qqgong",
		]));
	set("objects",([
	       __DIR__"npc/fakequeen":1,
	       __DIR__"npc/ruichu":1,
		]));
	set("item_desc",([
	    "cabinet":"一个大衣柜，好像没有上锁。\n",
	    "大衣柜":"一个大衣柜，好像没有上锁。\n",
		]));
	setup();
	set("nobook3",1);	
}
void init()
{       add_action("do_open","open");
	add_action("do_recover","recover");
        add_action("do_recover","xian");
	add_action("do_pull","pull");
}
int do_open(string arg)
{	object who,queen,book;
	who=this_player();
	book=new(__DIR__"obj/book14_4");
	queen=new(__DIR__"npc/realqueen");
	if(!arg||arg=="")
	 return notify_fail("你要打开什么？\n");
	if(arg=="cabinet"||arg=="大衣柜")
	  {
	   if(query("havebook4"))
		return notify_fail("你把大衣柜打开了，但没有发现你感兴趣的东西。\n");
	   if(who->query("huanggong/haspi3")&&!query("havebook7"))
	     {
		 message_vision("$N把衣柜打开，发现里边有一床棉被。\n",who);
		 if(random(5))
		   {say("棉被里似乎有一搂秀发，你拉开棉被一看，赫然又一个太后！！！\n");
		    who->set_temp("savequeen",1);
		    set("havebook4",1);
		    queen->move(this_object());
		    return 1;
		   }
		 else
		  {message_vision("棉被下边好像有东西，$N拉开棉被一看，赫然是一本经书！\n"+
				  "$N把它塞进自己的怀里。\n");
		   set("havebook4",1);
		   book->move(who);
		   return 1;
		  }
	    }
	return notify_fail("你把大衣柜打开了，但没有发现你感兴趣的东西。\n");
        }
       return notify_fail("看仔细了，这个屋子里没有你要开的东东。\n");
}
int do_recover(string arg)
{	object who;
	who=this_player();
	if(!arg||arg=="")
		return notify_fail("你要掀开什么？\n");
	if(!query("nobook3"))
	 {
	  if(arg=="被褥")
	    {  message_vision("$N掀开被褥，发现床板上有个小铜环。\n",who);
		who->set_temp("marks/recovered",1);
		return 1;
	    }
	 }
	return notify_fail("你要掀开什么？\n");	
}

int do_pull(string arg)
{	object who,book;
	who=this_player();
	book=new(__DIR__"obj/book14_7");
	if(!arg||arg=="")
	   return notify_fail("你要拉什么？\n");
	if(arg=="铜环")
	{
	  if(!who->query_temp("marks/recovered"))
	     return notify_fail("看仔细了，这个屋子里没有什么铜环。\n");
	  message_vision("$N伸指一拦铜环，一块宽约一尺，长约两尺的木板应手而起。\n",who);
	 if(query("havebook7"))
	   { say("下边是个长方形的暗格，里边空空如也。\n");
	     return 1;
	   }	
	 else 
	  {
	  message_vision("下边是个长方形的暗格，赫然放着一本白绸子镶边的经书。\n\n"+
		"$N把它拿出来放进自己的怀里。\n",who);
	  book->move(who);
	  set("havebook7",1);
	  return 1;	
	   }
	}
	return notify_fail("这个屋子里没有你要拉的东西。\n");
}
	
