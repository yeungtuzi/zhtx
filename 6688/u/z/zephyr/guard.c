//丁鹏的化身
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(CYN"丁鹏"NOR, ({ "ding peng","ding"}) );
	set("long",CYN@LONG
他的脸很清秀，身体也很健康，说起话来显得活力充沛，
生气蓬勃，笑起来的时候，常常会露出幼稚天真的孩子气，
就像是一个你从小看着他长大的大男孩。
但是丁鹏已经不是孩子了。这三个月里，他已连续击败了
三位在江湖中极负盛名的剑客。
LONG NOR
	 );

	set("title",CYN"圆月"WHT"弯刀"NOR);
	set("age", 50);
	set("str", 100);
	set("int", 30);
	set("cor", 100);
	set("cps", 100);                       
	set("per", 25);
	set("con", 30);
	set("no_get",1);

	set("atman", 1000);
	set("max_atman", 1000);

	set("force", 20000);
	set("max_force", 10000);
	set("force_factor", 100);

	set("mana", 1000);
	set("max_mana", 1000);

	set("max_kee",50000);

        set("attitude","heroism");
		set_skill("force", 100);
		set_skill("strike", 100);
		set_skill("sword", 100);
		set_skill("blade", 100);
		set_skill("parry", 100);
		set_skill("dodge", 100);
		set_skill("move", 100);
		set_skill("perception", 100);
	    set("skill_mark/spring-blade",1);

			
		set_skill("celestial", 100);
		set_skill("celestrike", 100);
		set_skill("spring-blade", 100);
		set_skill("pyrobat-steps", 100);
		map_skill("force", "celestial");
		map_skill("strike","celestrike");
		prepare_skill("strike", "celestrike");
		map_skill("blade", "spring-blade");
		map_skill("dodge", "pyrobat-steps");
		map_skill("move", "pyrobat-steps");
        set("combat_exp",400000+400*random(100));
        set("bellicosity",1000);
        set_temp("apply/attack",60);
        set_temp("apply/armor",40);
        setup();
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/blade")->wield();

}

void set_level(int i)
{
		set_skill("celestial", 1+random(50)+i);
		set_skill("celestrike", 1+random(50)+i);
		set_skill("spring-blade", 1+random(50)+i);
		set_skill("pyrobat-steps", 1+random(50)+i);
        set("combat_exp",5000000+random(1000)*i);
        ::setup();
}

void invocation(object who)
{
        int i;
        object *enemy;
        message("sound", CYN"\n你忽然听到一道犀利的金刃劈风的声音，紧接着"+name()+ CYN"如天兵一般忽然出现：英雄莫慌，丁鹏在此。\n" NOR, environment(), this_object() );
		enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) 
				{
                        kill_ob(enemy[i]);
						if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
				}
        }
        set_leader(who);
        message_vision("\n$N挥动手中圆月弯刀，加入战团!\n", this_object(), who);
		command("exert roar");
        set("possessed",who);
        who->add_temp("dingpeng_amulet",1);       
}

int chat()
{
        object owner;

        if( !is_fighting() || !objectp(owner=this_object()->query("possessed")) || !owner->is_fighting() || environment(this_object()) != environment(owner) )
        {
				call_out("leave", 1);
        }
        return 1;
}

void leave()
{
        object owner;
        remove_call_out("leave");
		if( objectp(owner = query("possessed")) )
		{
			owner->add_temp("dingpeng_amulet",-1);                
		}
        message_vision(HIG"\n丁鹏抱拳道：就此告别！\n" NOR,this_object());
        destruct(this_object());
}
void die()
{
	call_out("dest_amulet",1);
}
void dest_amulet()
{
	object owner, amulet;

	remove_call_out("dest_amulet");
	
	message_vision(HIR "\n丁鹏仿佛无法相信这个事实，缓缓的摔倒在地。\n" NOR,this_object() );
	message_vision(CYN "\n丁鹏手中圆月弯刀铮的一声碎成了几片。\n\n" NOR,this_object() );

	if( objectp ( owner = query("possessed") ) )
	{
		amulet = present("pixie wenyu", owner);
		amulet->unequip();
		destruct(amulet);
		message_vision( owner->name()+CYN"身上的辟邪温玉也随之碎成了几片。\n" NOR,this_object() );
	}
	call_out("self_dest",1);
}
void self_dest()
{
	object owner;
	if( objectp(owner = query("possessed")) )
	{
		owner->add_temp("dingpeng_amulet",-1);                
	}
	::die();
}
