// madcity.c

#include <ansi.h>

inherit ROOM;
#define SAVE_DIR "/data/dynaroom/"

int do_kill(string arg);
int do_halt(string arg);
int do_get(string arg);

int restore()
{
        int i;     
 	string file,domain,*dir;
 	domain="";
        file = file_name(this_object());
 	dir=explode(file,"/");
 	for(i=0;i<sizeof(dir)-1;i++)
 		domain+="/"+dir[i];
 	set("domain",domain);
 	file=file+".c";
 	i="/ldg/std/dynamapd"->load_room(domain,file);
        return i;
}

void setup()
{
	seteuid(getuid());
	restore();
	reset();
}


void init()
{
	object me = this_player();
	if( userp(me) )
		me->delete("env/invisibility");
	add_action("do_surrender","surrender");
	add_action("do_kill","kill");
	add_action("do_quit","quit");
	add_action("do_learn","learn");
	add_action("do_learn","study");
	add_action("do_learn","practice");
	add_action("do_learn","exercise");
	add_action("do_learn","respirate");
	add_action("do_learn","meditate");
	add_action("do_learn","xiulian");
	add_action("do_exert","exert");
	add_action("do_conjure","conjure");
	add_action("do_burn","burn");
	add_action("do_summon","summon");
	add_action("do_pray","pray");	
	add_action("do_get","get");
	add_action("do_attract","attract");
}                                    

int no_fly() 
{
	return 1;
}

int do_quit()
{
	object me;
	me=this_player();
	me->set("force",0);
	return 0;
}

int do_kill(string arg)
{
	object me,obj;
	string callname;

	me = this_player();
	if( !arg )
	{
		write("你想杀谁？\n");
		return 1;
	}             	
	if(!objectp(obj = present(arg, environment(me))))
	{	
		write("这里没有这个人。\n");
		return 1;
	}
	if( !obj->is_character() || obj->is_corpse() )
	{
		write("看清楚一点，那并不是活物。\n");
		return 1;
        }           
	if( userp(obj) && !living(obj) )
	{
		write("都这样了你还要打？趁人之危，不要太无耻了。\n");
		return 1;
	}
	if(obj==me)
	{
		write("用 suicide 指令会比较快:P。\n");
		return 1;
	}

	callname = RANK_D->query_rude(obj);

	message_vision("\n$N对著$n喝道：「" 
		+ callname + "！今日不是你死就是我活！」\n\n", me, obj);

	if( !userp(obj) ) {
                me->kill_ob(obj);
		obj->accept_kill(me);
		obj->kill_ob(me);
	}

        me->bihua_ob(obj);
	obj->bihua_ob(me);
	tell_object(obj, HIR "如果你要和" + me->name() 
		+ "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);

	return 1;
}

int do_learn(string arg)
{
        write("这里只许杀人放火，不许学习。\n");
        return 1;
}

int do_conjure(string arg)
{
	if( !arg )
		return 0;
	if( strsrch(arg,"drift") != -1 )
	{
		write("这里不许用游识神通。\n");
		return 1;
	}
	return 0;
}

int do_exert(string arg)
{
	object me;
	me=this_player();
	if( !arg )
		return 0;
        if( strsrch(arg,"fly") != -1 )
        {
                write("也不看看这里是什么地方，神雕是飞不进来的。\n");
                return 1;
        }
        return 0;
	if( strsrch(arg,"heal") != -1 )
	{
		if(me->query("eff_kee")>=me->query("max_kee"))
		{
			write("好好的heal什么。\n");
			return 1;
		}
	}
	return 0;
}

int do_get(string arg)
{
        object ob;

        //不许巫师来帮助get,包括immortal
        if( wiz_level(this_player()) )
        {
                write("这里不许巫师乱拣东西。\n");
                return 1;
        }

        if( (ob=present(arg) ) && ob->is_character() )
        {
                write("这里禁止背负生灵。\n");
                return 1;
        }

        return 0;
}

int do_attract(string arg)
{
        object ob;

        //不许巫师来帮助attract,包括immortal
        if( wiz_level(this_player()) )
        {
                write("这里不许巫师挖宝。\n");
                return 1;
        }
        return 0;
}

int do_pray(string arg)
{
        write("这里禁止使用玛瑙手镯。\n");
        return 1;
}

int do_summon(string arg)
{
        //不许巫师来帮助summon
        if( wizardp(this_player()) )
        {       
                write("你想干什么？这里不许SUMMON人过来。\n");
                return 1;
        }
        return 0;
}

int do_surrender(string arg)
{
        object me,enemy;
        string menpai_name,master_name,msg;
        
        me = this_player();
        if( !me->is_fighting() )
                return 0;

        message_vision(GRN"\n\n$N突然双膝跪地，磕头如捣蒜：我投降！我投降！\n"
                        "求您大人有大量，就放我这可怜虫一马吧。\n"NOR
                        RED"\n只见几个庄丁过来三下两下就把$N拖了出去。\n",me);

        if( menpai_name = me->query("family/family_name") )
                msg = "想不到"+me->query("name")+"堂堂"+menpai_name+"弟子，居然如此无用。\n";
        else 
                msg = "想不到"+me->query("name")+"一副趾高气扬的模样，居然如此无用。\n";

        if( enemy = me->query_temp("last_opponent") )
                CHANNEL_D->do_channel(enemy,"chat",msg);

        if( master_name = me->query("family/master_name") )
        {
                msg = master_name+"定是有眼无珠，才收下你这无能之辈。\n";
                if( enemy )
                        CHANNEL_D->do_channel(enemy,"chat",msg);
        }
        
        if( enemy )
        {
                msg = RANK_D->query_self_rude(enemy)+"今日杀你，如杀一狗耳。"+RANK_D->query_rude(me)+"你滚吧。 \n";
                CHANNEL_D->do_channel(enemy,"chat",msg);
        }

        me->remove_all_killer();

        //对投降进行惩罚
        if( (me->query("combat_exp")) > 800000)
                me->add("combat_exp",-25000);
        if( (me->query("wabao_combat_exp")) > 800000)
                me->add("wabao_combat_exp",-25000);
                
        if( (me->query("faith")) > 100)
                me->add("faith",-100);

        me->unconcious();
        me->move("/d/moyu/entrance");      
        return 1;
}


