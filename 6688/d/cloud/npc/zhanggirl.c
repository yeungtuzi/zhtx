// zhanggirl.c
//write by lysh

inherit NPC;

void create()
{
        set_name("张小姐", ({ "zhang xiao jie","zhang"}) );
        set("gender", "女性" );
        set("age", 22);
        set("long",
                "她是张百万的掌上明珠，才艺双全。她手里拿张纸条。\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                say("张小姐说:“听说这位"+RANK_D->query_respect(ob)+"琴意高超，故请来一见。”\n");                 remove_call_out("greeting");
                call_out("greeting", 5, ob);
        }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case	 0:
		     say ("张小姐把手里的纸撕成四片，然后就向北侧走去。\n");
		     remove_call_out("destructing");
                     call_out("destructing", 1,this_object());
			break;
                       }
}

void destructing(object obj)
{
	destruct(obj);
}