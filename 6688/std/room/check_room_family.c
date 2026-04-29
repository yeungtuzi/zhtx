// can be include in a room set with "family"
int valid_enter(object ob) {
	string fam = query("family");
	if(!userp(ob)) return -1;
	if(wizardp(ob)) return 2;
	if( fam && fam != ob->query("family/family_name")) {
		notify_fail("你不属于"+fam+"，不能进入"+fam+"的休息室。\n");
		return -1;
	}
	else return 1;
}
