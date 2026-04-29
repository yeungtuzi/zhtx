// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "大河");
	set("long", @LONG
水流很急，你耳边全是水声，什么也看不见…
在这条河里有几个江洋大盗，在这干没本钱的买卖，后来被
官府剿灭了。可据说还有珍宝没有找到，就埋在这大江的底下。
也有不少人到此寻宝，往往空手而归，甚至潜下去后再也没上来。
最好还是赶快上岸吧。
LONG
	);


	setup();
}

void init()
{	object ob;
	add_action("no_quit", "quit");
	add_action("do_swim", "swim");
        add_action("do_dive", "dive");

	if( interactive( ob = this_player()))
	{
	remove_call_out("sinking");
	call_out("sinking", 1, ob);
	}
}

int dive(object ob)
{
    int i,damage;
    if( environment(ob) == this_object())
    { 
        message_vision(HIW"$N一个猛子扎入水中。 \n", ob);
        damage = random(5)+50;
        i = (int)ob->query("kee");
        ob->set("kee", (int) i - damage);
        this_object()->move("/d/hua/bottum");
     }
     return 1;
}
       
int sinking(object ob)

{
	int i;
	int damage;
        if( environment(ob) == this_object())
	{
	message_vision(HIW"$N感觉越来越游不动了, 身体直往下沉。\n", ob);
	message_vision(HIW"$N不时被涌来的大浪呛了几口水！！\n"NOR, ob);
	damage = random(5)+50;
	i =  (int)ob->query("kee");
	ob->set("kee",(int) i - damage);
	if( environment(ob) == this_object())
	call_out("sinking",random(5)+5, ob);	
	}
	else

	return 1;
}

int no_quit()
{
        object me;
        me = this_player();
        if (me->query("marks/点菜")) {
                message_vision("$N刚想溜之大吉，但一想到还欠一屁股债就留下了。\n", me);
                return 1;
        }
        return 0;
}

void check_trigger()
{
        object me;
        me = this_player();

        if ((int)query("trigger") == 13) {
                me->delete("marks/点菜");
/*
                message_vision("$N终于游到了岸边, 你爬上岸一看, 你竟然到了……\n", me);
                me->move("/d/resort/small_river");
*/
		message_vision("$N终于游到了岸边,你爬上岸一看,咦？怎么又回来了？\n",me);
		me->move(__DIR__"road2");
                delete("trigger");
                return;
        }
 

        if ((int)query("trigger") < 0) {
                message_vision("$N又游回原来的岸边。\n", me);
                me->move(__DIR__"road2");
                delete("trigger");
                return;
        }
}

int do_swim(string arg)
{
        int i;
        if (!arg || arg == "") {
                write("你往北游还是往南游？\n");
                return 1;
        }
        if (arg == "north" || arg == "n") {
                add("trigger", 1);
                write("你奋力向北岸游去……\n");
                check_trigger();
                return 1;
        }
        if (arg == "south" || arg == "s") {
		i = (int)query("trigger")-1;
                delete("trigger");
		add("trigger", i);
                write("你奋力向南岸游去……\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}
