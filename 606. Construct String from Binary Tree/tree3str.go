package tree2s

import (
	. "leetcomm"
	"strconv"
)

func tree2str(t *TreeNode) string {
	options := []func(t *TreeNode) string{tree2str0, tree2str1}
	return options[1](t)
}

/*-------------------------------------------------------
      Method 1
-------------------------------------------------------*/
func tree2str1(t *TreeNode) string {
	if t == nil {
		return ""
	}
	l := tree2str1(t.Left)
	r := tree2str1(t.Right)
	res := strconv.Itoa(t.Val)
	if l != "" || r != "" {
		res += "(" + l + ")"
	}
	if r != "" {
		res += "(" + r + ")"
	}
	return res
}

/*-------------------------------------------------------
      Method 0
-------------------------------------------------------*/
func tree2str0(t *TreeNode) string {
	return string(dfs(t))
}

func dfs(t *TreeNode) []byte {
	if t == nil {
		return nil
	}
	l := dfs(t.Left)
	r := dfs(t.Right)
	res := itoa(t.Val)
	if l != nil || r != nil {
		res = append(res, '(')
		res = append(res, l...)
		res = append(res, ')')
	}
	if r != nil {
		res = append(res, '(')
		res = append(res, r...)
		res = append(res, ')')
	}

	return res
}

func itoa(a int) []byte {
	ret := make([]byte, 0)
	neg := false
	if a < 0 {
		neg = true
		a *= -1
	}
	if a < 10 {
		ret = append(ret, '0'+byte(a))
	} else {
		for a > 0 {
			ret = append(ret, '0'+byte(a%10))
			a /= 10
		}
	}
	for i := 0; i < len(ret)/2; i++ {
		ret[i], ret[len(ret)-1-i] = ret[len(ret)-1-i], ret[i]
	}

	if neg {
		return append([]byte{'-'}, ret...)
	} else {
		return ret
	}
}
