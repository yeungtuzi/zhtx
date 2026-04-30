// reclaim.c

int main(object me, string arg)
{
	// 2026-04-30: unused variable commented out
	// int mem;

	write("整理结果，共清除 " + reclaim_objects() + " 个变数。\n");
	return 1;
}
