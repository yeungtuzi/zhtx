// zhanggirl.c
//write by lysh

inherit NPC;

void create()
{
        set_name("张小姐", ({ "zhang xiao jie","zhang"}) );
        set("gender", "女性" );
        set("age", 22);
        set("long",
                "她是张百万的掌上明珠。\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query_temp("nofindout")) return;
        switch( random(1) ) {
                case 0:
		     remove_call_out("setting");
                     call_out("setting", 1);
			break;
                       }
}

void setting(object obj)
{
object *inv;
object con, item;
	
con = present("huacao", environment());
inv = all_inventory(con);
if( !sizeof(inv)&& random(3)) {
	item = new(__DIR__"obj/dice.c");
	item->set_amount(3);
	item->move(con);                

}
}