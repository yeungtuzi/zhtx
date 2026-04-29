// Created by lysh
// data: 1997.10.17
              
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("败家子", ({ "baijia zi" , "zi" }));
	set("title",HIC"游手好闲"NOR);
	set("long",
	"一个整天无所实事的败家子。\n");
	set("gender", "男性");
	set("age", 25);
	set("chat_chance", 1);
        set("chat_msg",({
         "败家子说：“长安赌场的骰子一定掺水银了，要是我有本钱，一定用玉宝轩的骰子发大财。”\n",
         }));

	set("attitude", "peaceful");
	set("combat_exp", 100);
	setup();
        carry_object(__DIR__"obj/shaizi");  
        carry_object(__DIR__"obj/cloth")->wear();

}

int accept_object(object me, object obj)
{
      object obj1; 
      if(obj->name(1)!="象牙骰子") return 0;
      if(obj->is_character()) return 0;
       command("say 多谢这位" + RANK_D->query_respect(me) + "，这玉宝轩的象牙骰子，一定会让我大杀八方的。");
       command("say 这张进长安赌场内室的请帖就送给你吧。我的赌技恐怕还嬴不了他们的大管家。");
        obj1=new(__DIR__"obj/qingtie.c"); 
        obj1->move(me);
        remove_call_out("destroying");
        call_out("destroying", 1,obj);
           
       return 1;

}
void destroying(object obj)
{
        destruct(obj);
        return;
}
