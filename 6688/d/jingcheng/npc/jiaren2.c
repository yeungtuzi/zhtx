// jiaren.c
// Made by ysgl (1997.10.23)

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("青衣家人", ({"qingyi jiaren", "jiaren" , "qingyi" }));
	set("gender", "男性"); 
	set("long", 
	"一个普普通通的青衣家人，脸上带着笑容。\n");    
	set("age", 35);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
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
        say( "青衣家人躬身道：这位" + RANK_D->query_respect(ob) + "，老爷和小姐已经搬回绮云镇去了。阁下既然妙解音律，不妨到绮云镇一游。小姐一定会很高兴的。\n");

}
