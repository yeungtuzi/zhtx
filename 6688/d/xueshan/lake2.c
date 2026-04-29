// Room: /d/xueshan/lake2.c
//by tlang for 混世神剑

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
	set("short", BLK"断龙潭"NOR);
	set("long", @LONG
水流很急，你耳边全是水声，什么也看不见…
LONG
	);

	setup();
}

void init()
{	object ob;
	add_action("no_quit", "quit");
	add_action("do_swim", "swim");
        
	if( interactive( ob = this_player()))
	{
	remove_call_out("sinking");
	call_out("sinking", 1, ob);
	}
}
      
int sinking(object ob)
{
	int mykee,mycps,damage;
	
        if(!environment(ob) || environment(ob) != this_object())
		return 0;
	mycps=ob->query("cps");
	message_vision(HIW"$N感觉越来越难受, 身体直往下沉。\n", ob);
	message_vision(RED"$N不时被涌来的黑水呛进口中！\n"NOR, ob);
	damage =50*1/mycps+random(5);
	mykee =  (int)ob->query("kee");
	ob->set("kee",(int) mykee - damage);
	call_out("sinking",random(15)+5, ob);	
		return 1;
}

int no_quit()
{
        object ob = this_player();

        if ( environment(ob)==this_object() ) {
                message_vision("$N想溜之大吉，但困在水浪中，哪里作得了主。\n", ob);
                return 1;
        }
        return 0;
}

void check_trigger()
{
        object ob = this_player();

        if ((int)query("trigger") == 3) {
		if( !ob->query("my_owner") )
		{	
		message_vision("$N终于游到潭边的洞中。\n",ob);
		ob->move(__DIR__"myhell");
		delete("trigger");
			return;
		}
		message_vision("$N终于游到潭边的洞中。\n",ob);
		ob->move(__DIR__"myhell2");
                delete("trigger");
                	return;
	}

        if ((int)query("trigger") < 0)
	{
                message_vision("$N在水中不停地打转，找不到出路。\n", ob);
	   //     me->move(__FILE__);
                delete("trigger");
                return;
        }
}

int do_swim(string arg)
{
        int i;

        if (!arg || arg == "") {
                write("你往上游还是往下游？\n");
                return 1;
        }
        if (arg == "up" || arg == "u") {
                add("trigger", 1);
                write("你奋力向上边的一个隐现的石洞游去……\n");
                check_trigger();
                return 1;
        }
        if (arg == "down" || arg == "d") {
		i = (int)query("trigger")-1;
                delete("trigger");
		add("trigger", i);
                write("你往水潭深处一个猛子扎了下去……大概不想活了。\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}
