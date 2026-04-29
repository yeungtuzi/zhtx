// sergeant.c

inherit NPC;

void create()
{
        set_name("船老大", ({ "chuan laoda","laoda" }) );
        set("long",
                "一位相貌威武的船老大，穿着渔夫的服色，可并不象长期出海的渔民。\n"
	);
        set("age", 29);
        set("combat_exp", 250000);
        set("env/wimpy", 10);
        set("str", 28);
        set("cor", 28);
        set("cps", 28);
        set("inquiry", ([
                "出海" : "这是渔船，决计不能载客的。"
        ]) );
        set_skill("dodge", 70);
        set_skill("unarmed", 60);
        set_skill("parry", 70);
        set_skill("sword", 75);

        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
        set_temp("apply/damage", 30);

        setup();
}

int accept_object(object me, object ob)
{

        if( ob->value() > 100000 ) {
		message_vision("$N压低声音对船老大说：实不相瞒，在下欲离开灵蛇岛。俗言道，与人方便，自己方便。。。\n",me);
		message_vision("$N取出"+ob->query("name")+"递给船老大。\n",me);
                command("say 那。。。我就不客气了，请坐稳，要开船了！");
		destruct(ob);
		remove_call_out("do_move");
		call_out("do_move",5,me);
                return 1;
        }
        return 0;
}
                                       
void do_move(object me)
{
	message_vision("船老大对$N说：到啦\n",me);
	me->move("/d/mingjiao/gangkou");
}
