// natured.c

inherit F_DBASE;

#define TIME_TICK (time()*60)

nosave int current_day_phase;
mapping *day_phase;
string *list;
mixed *test_list;
int t, size;
mixed *counter;

string *weather_msg = ({
	"天空中万里无云",
	"几朵淡淡的云彩妆点著清朗的天空",
	"白云在天空中飘来飘去",
	"厚厚的云层堆积在天边",
	"天空中乌云密布",
});

mapping *read_table(string file);
void init_day_phase();
void time_adjustment();

void test()
{
	int i;
	mapping *d;
	list = get_dir("/adm/etc/nature/*.local");
	size = sizeof(list);
	counter = allocate(size+1);
	// counter[1][0] : phase, counter[1][1] : time
	for(i=0;i<size;i++) {
		counter[i] = allocate(2);
	}
	if(!size) return;
	test_list = ({});
	for(i=0;i<size;i++) {
	d = read_table("/adm/etc/nature/"+(string)list[i]);	
	test_list += ( {allocate_mapping(sizeof(d))} );
	test_list[i] = d;
	}		
	return;
}

mixed *query_data(int i) {return test_list[i];}

void create()
{
	mixed *local;
	int i, j, ok, tmp;
	local = localtime(time()*60);
	t = local[2] * 60 + local[1];
	i = t % 30;
	i = 30 - i;
	t = t + i;
	call_out("time_adjustment", i);
	test();
	set("name","天气测试");
	set("id", "na");
	for(i=0;i<size;i++) {
		tmp = t;
		ok = 0;
		j = 0;
		while(!ok) {
			if(tmp < test_list[i][j]["length"]) {
				counter[i][0] = j+1;
				counter[i][1] = test_list[i][j]["length"] - tmp;
				ok = 1;
			} else {
				tmp = tmp - test_list[i][j]["length"];
				j++;
			}
		}
		CHANNEL_D->do_channel(this_object(), "sys", (string)list[i]+"::"+(string)counter[i][0]+"-"+(string)counter[i][1]);
	}
}

void heart_beat()
{
	int step, i, j;
//	object ob;
//	ob = find_player("elon");
//	if (!ob) return;
//	tell_object(ob, "[WEATHER]: heart beat is called.\n");
//	tell_object(ob, "[TIME]: "+(string)t+" \n");
	t = t + 30;
	CHANNEL_D->do_channel(this_object(), "sys", (string)t+":"+(string)size);
	if(!size) return;
	for(i=0;i<size;i++) {
		counter[i][1] = counter[i][1] - 30;
		//CHANNEL_D->do_channel(this_object(), "sys", (string)counter[i][1]);
		if(counter[i][1] == 0) {
			CHANNEL_D->do_channel(this_object(), "sys", list[i]+"::"+(string)test_list[i][counter[i][0]]["time_msg"]);
			counter[i][0]++;
			if(counter[i][0] > sizeof(test_list[i])) counter[i][0] = 0;
			counter[i][1] = (int)test_list[i][counter[i][0]]["length"];
		}
	}
	if (t==1440) t = 0;
	return;
}

void time_adjustment()
{
	set_heart_beat(15);
	return;
}


/*
void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
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

void update_day_phase()
{
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase
void event_dawn() {

        ob = users();
        for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !is_ghost(ob[i]) ) continue;
                if( environment(ob[i])->query("ghostplace") ) continue;
		tell_object(ob[i],"天快亮了，你仿佛听到心里有一个声音在呼唤：快走吧，快走吧！\n");		
	}
}

void event_noon()
{
	object *ob;
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
	}
}

string outdoor_room_description()
{
	return "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

*/
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


mapping *query_day_phase() { return day_phase; }
