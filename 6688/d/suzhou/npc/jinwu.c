//jinwu.c
//by tlang

#include <ansi.h>
inherit NPC;
inherit F_QUEST;
void re_rank(object);

void create()
{
        set_name(YEL"金乌"NOR,({"jin wu","jin"}));
        set("nickname", HIW "白眉老人" NOR);
        set("title",GRN "镖局" NOR + YEL "前任" NOR+GRN"总镖头"NOR);
        set("long",@LONG
        神话中有寒于氏血战救护人类的传说，相传寒于战死后，化为十三神
怪，其中就有金乌，这老人当年血战湘江，拯救了当代武林，人们为表感激，
称其为金乌，以示尊敬，他的本名反而被遗忘了。
LONG
	);
        set("gender", "男性");
        set("age", 80);
        set("attitude", "peaceful");
        set("shen_type", 2);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
	set("per", 25);

        set("max_kee", 2000);
        set("max_gin", 800);
	set("max_sen", 800);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 80);
        set("combat_exp", 1500000+random(500000));
        set("score", 50000);

        set_skill("force",150);
	set_skill("blade",150);
        set_skill("dodge", 150);
	set_skill("strike",150);
        set_skill("parry", 150);
        set_skill("sword", 150);
	set_skill("unarmed",150);
        set_skill("xiaoyaoyou",100);
        set_skill("literate", 100);
       	set_skill("wuchang-zhang", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("cibei-dao", 120);	

	map_skill("blade", "cibei-dao");
	map_skill("strike", "wuchang-zhang");
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "cibei-dao");
       
        prepare_skill("blade", "cibei-dao");
	prepare_skill("strike", "wuchang-zhang");

        setup();
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}

void init()
{

        object me, ob;
       
        ::init();
        add_action("give_quest","quest");
        ob = this_player();
        me = this_object();
 
      	remove_call_out("greeting");
	call_out("greeting",1,ob);
}

void greeting()
{
	object ob=this_player();
	object me=this_object();
	
	if( !ob || environment(ob) != environment() || !ob->query("biao_ju") ) return;
	command("smile");
	re_rank(ob);
}

void re_rank(object student)
{
        int exp;

//	string old_rank;
//	old_rank=student->query("title");

        exp = (int) student->query("combat_exp");
        if( exp <= 10000 ) {
                student->set("nickname",RED"趟子手"NOR);
                return ;
        } else if ( exp <= 100000 ) {
                student->set("nickname",BLU"趟子手"NOR);
                return ;
        } else if ( exp <= 200000 ) {
                student->set("nickname",MAG"镖头"NOR);
                return ;
        } else 
                student->set("nickname",YEL"副总镖头"NOR);
                return ;
}


// check if bribe is valid

int valid_bribe(object who,int val) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
	return(0);
}


// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

