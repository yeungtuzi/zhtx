// father.c

inherit NPC;

void create()
{
        set_name("老者", ({ "old man"}) );
        set("gender", "男性" );
        set("age", 92);
        set("long", "你看到一个须发斑白的老人,精神矍铄。\n");
        set("str", 19);
        set("int", 16);
        set("combat_exp", 4500000);
        set("score", -500);
        set("attitude", "heroism");
        set("max_force",330);
        set("force",410);
        set("force_facter",3);
        
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set("inquiry", ([
                "name" : "老夫独孤求和！",
 ]) );

        setup();
        add_money("silver", 4);
        carry_object("/obj/cloth")->wear();
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
        if( !ob || environment(ob) != environment() ) return;
	return;
}
