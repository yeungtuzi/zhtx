// /d/xizang/npc/snowman.c

inherit NPC;

void create()
{
        set_name("雪人", ({ "snowman", "man" }));
        set("long", @TEXT
这是就是传说中的雪人,是一种介于人和类人猿之间的庞大生物,喜欢喝酒,力大
无穷,被认为十分凶猛,但其实胆子并不大.
TEXT
);
	if (random(10)<5) set("gender", "男性"); else set("gender", "女性");
        set("age", 1+random(50));
        set("attitude", "heroism");
        set("str", 25+random(100));
        set("combat_exp", 10000+10000*random(10));

        set_skill("unarmed",3+2*random(100));
        set_skill("parry", 3+2*random(100));
	set_skill("dodge", 20+3*random(100));

        setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object wine;
	if (ob->query_temp("snowman")) {
		say("哇..哇..\n");
		message_vision("雪人对$N露出友善的笑容.\n", ob);
	} else {
	if ((ob->query("bellicosity") > 100) || (ob->query("MKS") > 100)) {
		say("呜....哇....\n");
		message_vision("雪人好象有点儿害怕$N.\n", ob);
		call_out("do_leave", 3);
		}
	}
}

void do_leave()
{
	message("vision","雪人匆匆忙忙地离开了.\n",
		environment(this_object()));
	desctruct(this_object());
}

int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") <= 3) {
            command("shake");
            return 0;
        }
        else {
            command("nod");
            who->set_temp("snowman",1);
            return 1;
        }
    }
    else return 0;
}
