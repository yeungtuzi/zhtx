//zhennan.c
#include <ansi.h>
inherit NPC;
string *leave_msg = ({     
	WHT"林镇南服下大补丸，盘膝在地开始疗伤 .\n",NOR
	WHT"林镇南稀里哗啦的吐出几团瘀血 .\n",NOR
	WHT"林镇南双臂一张，把身上的绳子震得段段寸断 .\n",NOR
	WHT"林镇南说道: 这位" +RANK_D->query_respect(this_player())+",谢谢你救了我 .\n",NOR
	WHT"林镇南想了想，道: 这样吧你带我回到福威镖局，我告诉你一个秘密，好不好? .\n",NOR
	WHT"林镇南说道: 如果没有什么事情，我们现在走吧!\n",NOR
	});	
void create()
{
        set_name("林镇南", ({ "lin zhennan","lin","zhennan" }) );
        set("title", "林老镖头");
        set("gender", "男性" );
        set("age", 56);
        set("str", 30);
      
        set("long", @LONG
林镇南是福威镖局的总镖头,因为怀璧其罪,拥有辟邪剑谱而被余沧海抓到此处
逼供,每天都要受折磨,他双目无神,蓬乱的头发掩盖了饱受沧桑的脸,他的双手
双脚都被困住了,琵琶骨还被穿了一根牛筋,显然已经元气大伤了.
LONG
);
        set("max_gin", 500);
        set("eff_gin", 100);
        set("gin", 1);
        set("max_kee", 500);
        set("eff_kee", 1);
        set("kee", 1);
        set("max_sen", 500);
        set("eff_sen", 100);
        set("sen", 1);
        set("score", -500);
        set("combat_exp", 1000);
        set("attitude", "friendly");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
 "臭贼！ 休想从我的口中得到一点声息！\n",
        }) );

        setup();

        carry_object("/obj/cloth")->wear();
}


int accept_fight(object me)
{
      command("say 要杀就来，休想晦辱老夫.");
        return 0;
}


void init()
{
        object ob;
        if( interactive( ob = this_player()))
        remove_call_out("followhim");
        if((int) ob->query("marks/林平之本人") == 1)
        {
        set_leader(0);
        call_out("goaway", 5);
        }
        else {
        call_out("messageing",3);

        }
}

void messageing()
{
        object room;
        room = find_object("/open/hihi/jinbishi");
        if(environment() == room) {
        write("林镇南微微抬起头,冷眼看着你.\n");
        write("林镇南说道: 你是真心救我,还是想用计谋哄我？\n");
	write("林镇南说道: 如果你真的想救我，就给我找来一些医疗内伤的灵药来.\n");
}
}
void followhim(object ob)
{
	object room;
	room = find_object("/open/hihi/jinbishi");
	if(environment() == room)
	if( present(ob, environment()))
        set_leader(ob);

}

void goaway()
{
	destruct(this_object());
}

void die()
{
        int i;
        object killer;

        if(objectp(killer = query_temp("last_damage_from")))
            killer->set("marks/murder", 1);

        ::die();

}
int accept_object(object who, object ob)
{	who = this_player();
        if( (string)ob->query("id") !="spile" ){
                command("say 我现在受了很重的内伤，要非常灵药才能复原.\n");
                return 0;
        }	 

	message_vision(RED"林镇南说道: 这正是我要找的灵药，谢谢你了!\n"NOR,who);
	
        call_out( "leave_stage", 2, who, 0 );
        return 1;
}
void leave_stage(object who, int stage)
{
        object obj;
        tell_object(who, leave_msg[stage]);
        if( ++stage < sizeof(leave_msg) ) {
        call_out( "leave_stage", 4, who, stage );
        return;
     } 
        else call_out("followhim", 1, this_player());
                who->set("mark/pixie",1);
		command( "eat spile");
                who->set("marks/林平之", 1);

	        set("long", @LONG
林镇南是福威镖局的总镖头,因为怀璧其罪,拥有辟邪剑谱而被余沧海抓去逼供,
每天都要受折磨,他双目无神,蓬乱的头发掩盖了饱受沧桑的脸.
LONG
);
}
