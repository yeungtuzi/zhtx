//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);

	set_name(HIB"青衣刺客"NOR, ({ "qingyi cike","assassin","cike"}) );
	set("long",BLK@LONG
他穿着紧身的青衣，以青巾蒙面，身法快如急风，轻如飞絮，
手中一柄长剑更急如闪电，剑尖蓝光颤动，显有奇毒。
LONG NOR
	 );
	set("title",HIB"狂剑"NOR);
	set("age",21);
	set("percmd","exert kuihua");
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("mo-jian-jue", t+random(10));
	set_skill("kuihua-shengong", t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("jiuyin",t+random(10));


	map_skill("force","kuihua-shengong");
	map_skill("iron-cloth","jiuyin");
	map_skill("parry","mo-jian-jue");
	map_skill("dodge","kuihua-shengong");
	map_skill("move","kuihua-shengong");
	map_skill("sword","mo-jian-jue");


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
        if(ob=present("heiyi cike",environment()))
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
