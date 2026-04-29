// /d/xizang/class/gold_wh/npc/snowman.c

inherit NPC;

void create()
{
        set_name("雪人", ({ "snowman", "man" }));
        set("long", @TEXT
这是一个生活在喜马拉雅山上的雪人,他常被当作猿猴类猛兽,但实际上和人类
更加接近,并且也能学会武功.
TEXT
);
        set("gender", "男性");
        set("age", 41);
        set("attitude", "heroism");
        set("str", 65);
        set("combat_exp", 1000010);

        set_skill("unarmed",130);
        set_skill("parry", 130);
	set_skill("dodge", 230);

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
	if ((string)ob->query("family/family_name")=="密宗金轮派") {
		say("呜....呜....哇....哇....\n");
		this_object()->kill_ob(ob);
		ob->fight_ob(this_object());
	}
}
