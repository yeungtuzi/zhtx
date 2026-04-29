// madcity.c

#include <ansi.h>

inherit ROOM;

  int do_stay(string arg);
int do_kill(string arg);
int do_halt(string arg);
int do_get(string arg);
// no_fly() 防止有人飞进来
int no_fly() 
{

	return 1;
}

int full(mixed ob)
{
        string *conditions=({}),*list,arg;

        int i;

        if(!objectp(ob)) return 0;


        list = get_dir("/daemon/condition/");

        i = sizeof(list);
        while( i-- )
        {
                arg = list[i];
                if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                        conditions += ({arg[0..strlen(arg)-3]});      
	}
  
	i = sizeof(conditions);
        while(i--)
        {
           if( ob->query_condition(conditions[i]) > 0 )
                  ob->clear_condition(conditions[i]);

        }
        ob->clear_condition("threesmiles");//三笑逍遥散
        ob->clear_condition("super_poisons");//不死不休
        ob->clear_condition("zhang_qi");//瘴气
        ob->clear_condition("iceshock");//意寒毒
        ob->clear_condition("shengsifu");//生死符
        ob->clear_condition("slumber_drug");//蒙汗药
        ob->clear_condition("fushi-du");//腐尸毒

        return 1;
}

void create()
{
	setup();
}

int creature_die(object me)
{
	int i;
	object *inv,enemy;
	string menpai_name,msg,master_name;

	if( !me || !userp(me) ) return 0;
        message("system", HIR "\n你被打晕了....\n\n" NOR,me);
        tell_room(this_object(),me->query("name")+"被乾坤教徒扒了个精光，架了出去，扔出了宝库。\n");
me->add("potential",me->query("learned_points")-me->query("potential"));
	full(me);
	me->unconcious();

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
                msg = RANK_D->query_self_rude(enemy)+"今日杀你，如杀一狗耳。"+RANK_D->query_rude(me)
+"你滚吧。 \n";
                CHANNEL_D->do_channel(enemy,"chat",msg);
        }

        me->set_temp("be_defeated",1);
	inv = all_inventory(me);
	i = sizeof(inv);
	while(i--)
		if( !inv[i]->query("no_drop")) 
		inv[i]->move(this_object());	
 	me->move("/d/xanadu/inn");
	return 1;
}

void init()
{
	object ob;
	object me = this_player();
	
	ob = me;
	if( userp(me) )
		me->delete("env/invisibility");
	if( (wiz_level(ob) || raw_wiz_level(ob)) && wiz_level(ob)<5 && raw_wiz_level(ob)<
5 )
        {
                        return;
        }
	add_action("do_surrender","surrender");
	add_action("do_kill","kill");
	add_action("do_learn","learn");
	add_action("do_learn","study");
	add_action("do_conjure","conjure");
	add_action("do_burn","burn");
	add_action("do_quit","quit");
        add_action("do_stay","stay");
	add_action("do_get","get");	
	add_action("do_pray","pray");	
	add_action("do_summon","summon");
	add_action("do_update","emergency_out"); //在封闭出路的时候可以逃出去。
}                                    

//在幽明山庄的范围内任何地方都可以kill,而且不会计算pk_point
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

int do_burn(string arg)
{
	write("这里不许烧符。\n");
	return 1;
}

    int do_stay(string arg)
    {
      write("ok. \n");
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

	if( strsrch(arg,"shade") != -1 )
	{
		write("这里不许用隐识神通。\n");
		return 1;
	}

	return 0;
}

int do_quit(string arg)
{
	if( this_player()->is_fighting() )
	{
		write("正打着架就想开溜？没门！\n");
		return 1;
	}
	return 0;
}
                                         
int valid_leave(object me,string dir)
{
	if( me->is_fighting() )
	{
		return notify_fail("正打着架就想开溜？没门！\n");
	}
	return 1;
}

int do_get(string arg)
{
	object ob;

	//不许巫师来帮助get,包括immortal
	if( wiz_level(this_player()) || raw_wiz_level(this_player()) )
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

//在封闭通道的时候逃出去的最后方法。
// for debug only
int do_update(string arg)
{
	if( !arg || arg != "LetMeOut!" )
		return 0;
	if( !wiz_level(this_player()) )
		this_player()->receive_wound("sen",100); //防止有人滥用。
	call_other("/adm/daemons/dynamicd","regenerate_map",1); //重新连接地图，但是并不重新生成宝物和npc
	return 1;
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
                        RED"\n只见几个乾坤教徒过来三下两下就把$N拖了出去。\n",me);

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
	if( (me->query("wlshw")) > -100)
		me->add("wlshw",-1);
	//门派的惩罚
	if( (me->query("faith")) > 100)
		me->add("faith",-100);

	me->unconcious();
	me->move("/d/xanadu/inn");	
	return 1;
}
