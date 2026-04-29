//modified by yeung
// natured.c
#include <ansi.h>
#include <login.h>
#include <command.h>

#define TIME_TICK (time()*60)

nosave int current_day_phase;
nosave int current_season_phase;
nosave int current_weather_phase;

mapping *day_phase;
mapping *season_phase;
mapping *weather_phase;

mapping *read_table(string file);
void init_day_phase();
void init_season_phase();
void init_weather_phase();
string query_season() {return season_phase[current_season_phase]["name"];}

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
	season_phase = read_table("/adm/etc/nature/season_phase");
	init_season_phase();
	weather_phase = read_table("/adm/etc/nature/weather_phase");
	init_weather_phase();

}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
		(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}
void init_weather_phase()
{

	// Find the weather phase for now.

	current_weather_phase = random(sizeof(weather_phase));

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.

	call_out("update_weather_phase", 720+random(720) );
}

void init_season_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes

	// Find the season phase for now.
	for( i=0; i < sizeof(season_phase); i++)
		if( t >= season_phase[i]["length"] )
			t -= (int)season_phase[i]["length"];
		else
			break;

	current_season_phase = (i==0? sizeof(season_phase)-1: i - 1);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.

	call_out("update_season_phase",
		(int)season_phase[(current_season_phase+1) % sizeof(season_phase)]["length"] - t);
}

void update_day_phase()
{
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	if (!weather_phase[current_weather_phase]["sun_mask"])
		message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void update_weather_phase()
{
int i;
	remove_call_out("update_weather_phase");
	i = random(3) - 1;
	current_weather_phase += i;
	if (current_weather_phase < 0) current_weather_phase += 2;
	if (current_weather_phase >= sizeof(weather_phase) ) current_weather_phase -= 2;
//	current_weather_phase += i+current_weather_phase) % sizeof(weather_phase);
	if ( query_season()=="冬季" )
		message("outdoor:vision", weather_phase[current_weather_phase]["cold_msg"] + "\n", users());
	else
		message("outdoor:vision", weather_phase[current_weather_phase]["warm_msg"] + "\n", users());
	if( !undefinedp(weather_phase[current_weather_phase]["event_fun"]) )
		call_other(this_object(), weather_phase[current_weather_phase]["event_fun"]);
	call_out("update_weather_phase", random(720)+720);
}

void update_season_phase()
{
	remove_call_out("update_season_phase");

	current_season_phase = (++current_season_phase) % sizeof(season_phase);
	message("outdoor:vision", season_phase[current_season_phase]["time_msg"] + "\n", users());
	if( !undefinedp(season_phase[current_season_phase]["event_fun"]) )
		call_other(this_object(), season_phase[current_season_phase]["event_fun"]);
	call_out("update_season_phase", season_phase[current_season_phase]["length"]);
}

//以下函数将在每天的不同时辰被调用。
void event_dawn() {
	object *ob;
	int i;
	
        ob = users();
	message("outdoor:vision", "远处传来雄鸡的啼叫，天快亮了。\n", ob);        
        for(i=0; i<sizeof(ob); i++) {
                if( !environment(ob[i]) ) continue;
                if( !(ob[i])->is_ghost() ) continue;
                if( environment(ob[i])->query("ghostplace") ) continue;
                tell_object(ob[i],"天快亮了，你感觉精力在一点点的散去。朦胧中你仿佛听到心里有一个声音在呼唤：快-走吧，快走吧！\n");
        }                

}

void event_sunrise() {
        object *ob,theob,env;
        int i;
        ob = users();
        for(i=0; i<sizeof(ob); i++) {
                if( !environment(ob[i]) ) continue;
                if( !(ob[i])->is_ghost() ) continue;
                if( environment(ob[i])->query("ghostplace") ) continue;
		theob=ob[i];
		env=environment(theob);
                tell_object(theob, HIR "\n一道刺眼的阳光射到你的身上，你只感到天旋地转,\n浑身上下好象已经四分五裂!你感到身体弥漫开来，不停的下降、下降...\n" NOR);
	        theob->set("gin", 1);  theob->set("eff_gin", 1);
                theob->set("kee", 1);  theob->set("eff_kee", 1);
                theob->set("sen", 1);  theob->set("eff_sen", 1);
                theob->save();
		DROP_CMD->main(theob, "all");
                theob->move(DEATH_ROOM);
		message( "vision", HIY "\n" + "你忽然听见一声惨叫，面前的地上多出一片血水。\n" NOR , env, ({ theob }) );

        }
}

void event_morning()
{
	object zhang;

	//zhang wuji检查是否应该举行新的比武。

	load_object("/d/mingjiao/dadian");
	zhang = new("/adm/npc/zhangwuji");
	zhang->move("/d/mingjiao/dadian");                      
	destruct(zhang);
	if( !objectp((zhang = find_living("zhang wuji"))) )	
	{
/*

		zhang = new("/adm/npc/zhangwuji");
		zhang->move("/d/mingjiao/dadian");                      
*/
               return;
	}
	zhang->check_time();

	return;
}              

void event_noon()
{
	object *ob,shashou;
        object gelun;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "你觉得一阵晕眩，好像有一股能量从身上被人吸走了。\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "随著太阳升到天空的正中央，你觉得你的法力开始消失了。\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}                           
		//练七伤拳伤身的人会在半夜狂性大发。中午该恢复正常了
		if( (ob[i])->query("marks/qishang-hurt") )
		{
			tell_object(ob[i],"随著太阳升到天空的正中央，你渐渐恢复了神智。。。\n");
			(ob[i])->set("attitude","friendly");
		}
	}
        shashou = new("/d/wizard/npc/shashou");
	//gelun = new("/class/lama/gelun.c");
//        shashou->move("/d/snow/inn");
	//gelun->move("/d/guanwai/void.c");
	destruct(gelun);  
//        shashou->do_name();
}

void event_afternoon()
{
	return;
}

void event_evening()
{              
}

void event_night()
{
	return;
}

void event_midnight() 
{
	object *p;
	int 	i,size;

	p = users();  
	size = sizeof(p);
	//练七伤拳伤身的人会在半夜狂性大发。
	if( size )
        	for(i=0;i<size;i++)
			if( (p[i])->query("marks/qishang-hurt") > 2)
			{
				tell_object(p[i],"明月当空，对你露出了邪恶的笑容，你心头一阵烦躁，只是想杀人！\n");
				(p[i])->set("attitude","aggressive");
			}
	return;
}               

// 下列四个函数将在季节转换时被调用。
void event_spring()
{
	return;
}                                    

void event_summer()
{
	return;
}

void event_fall()
{
	return;
}

void event_winter()
{
	return;
}

// 下列四个函数将在天气变化时被调用。

//天空中万里无云
void event_sunshine()
{
	return;
}

//白云在天空中飘来飘去
void event_cloudy()
{
	return;
}

//天空中乌云密布
void event_overcloud()
{
	return;
}

//天上淅淅沥沥地下着小雨
//小雪花从天上慢慢飘下来
void event_snow()
{
	return;
}

//天上下着倾盆大雨
//天上飘着鹅毛大雪
void event_heavysnow()
{
	return;
}

string outdoor_room_description()
{
string str;
	str = "    ";
	if (weather_phase[current_weather_phase]["sun_mask"])
		str += "如果天气晴好的话，你会看到";
	str += day_phase[current_day_phase]["desc_msg"] + "。\n";
	if ( query_season()=="冬季" )
		str +=  "    " + weather_phase[current_weather_phase]["cold_msg"] + "。\n";
	else
		str +=  "    " + weather_phase[current_weather_phase]["warm_msg"] + "。\n";
	return str;
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

// This function is to read a regular type of data table for day_phase and
// etc.
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

int query_brightness() { return day_phase[current_day_phase]["brightness"]
			* weather_phase[current_weather_phase]["brightness"] /100
			* season_phase[current_season_phase]["brightness"] /100; }
		
int query_temperature() { return season_phase[current_season_phase]["temperature"]
			* weather_phase[current_weather_phase]["temperature"] /100
			* day_phase[current_day_phase]["temperature"] /100; }
int query_humidity() { return weather_phase[current_weather_phase]["humidity"]
			* day_phase[current_day_phase]["humidity"] /100
			* season_phase[current_season_phase]["humidity"] /100; }
			
mapping *query_day_phase() { return day_phase; }
mapping *query_season_phase() { return season_phase; }

