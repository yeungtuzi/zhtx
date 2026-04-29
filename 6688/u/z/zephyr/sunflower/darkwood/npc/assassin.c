//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);
	set_name(BLK"黑衣刺客"NOR, ({ "heiyi cike","assassin","cike"}) );
	set("long",BLK@LONG
他穿着紧身的黑衣，以黑巾蒙面，身法快如急风，轻如飞絮，
手中一柄长剑更急如闪电。
LONG NOR
	 );
	set("title",BLK"夜魔"NOR);
	set("age",21);
	set("percmd","exert kuihua");
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("pixie-sword", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("force",t+random(10));
	set_skill("stormdance",t+random(10));
	set_skill("kuihua-shengong",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("jiuyin",t+random(10));
	set_skill("perception", t+random(10));



	map_skill("force","kuihua-shengong");
	map_skill("sword","pixie-sword");
	map_skill("move","stormdance");
	map_skill("dodge","stormdance");
	map_skill("parry","pixie-sword");
	map_skill("iron-cloth","jiuyin");


	set("chat_chance",3);
	setup();

	carry_object("/obj/cloth/cloth")->wear();
	carry_object(__DIR__"obj/poisonsword")->wield();
	set("weapon_type","sword");

}                          
int hit_ob(object me, object ob, int damage)
{
	int n;
	n=(int)ob->query_condition("shw_poison");
	ob->apply_condition("shw_poison", 3+n);
	tell_object(ob, HIG "你觉得伤口一阵麻痒！\n" NOR );
}
                             
int killed_enemy(object ob)
{
	command("heihei");
}                 
                     
int accept_kill(object me)
{
        object ob;
        if(ob=present("qingyi cike",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("lvyi cike",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        return 1;
}
